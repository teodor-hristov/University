package main

import (
	"bufio"
	"container/list"
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"net/url"
	"os/exec"
	"strconv"

	"github.com/bwmarrin/dgvoice"
	"github.com/bwmarrin/discordgo"
)

const (
	channels  int = 2
	frameRate int = 48000
	frameSize int = 960
)

type MusicPlayer struct {
	voiceConn *discordgo.VoiceConnection
	playlist  *list.List
	isPlaying bool
	stop      bool
	next      bool
}

var mp MusicPlayer

func stop(mp *MusicPlayer) {
	if mp == nil {
		return
	}

	mp.stop = true
}

func next(mp *MusicPlayer) {
	if mp == nil {
		return
	}

	mp.next = true
}

func discordPlayMusic(guildId string, channelId string, songUrl string) error {

	voiceConn, err := session.ChannelVoiceJoin(guildId, channelId, false, false)
	if err != nil {
		return err
	}

	mp = MusicPlayer{isPlaying: true, voiceConn: voiceConn, stop: false, next: false}
	if mp.voiceConn.Ready {
		return playSong(songUrl, &mp)
	}

	return errors.New("Problem finding connecting.")
}

func playSong(songUrl string, mp *MusicPlayer) error {
	if mp.voiceConn == nil {
		return errors.New("voiceConnection error")
	}
	_, err := url.Parse(songUrl)
	if err != nil {
		return errors.New("Url is wrong.")
	}

	//old way to download music changed to yt-dlp due to slow download speed
	//youtubedl := exec.Command("youtube-dl", "-f", "worst", songUrl, "-o", "-")
	youtubedl := exec.Command("yt-dlp", "--extractor-retries", "3", "-f", "best", songUrl, "-o", "-")
	out, err := youtubedl.StdoutPipe()
	if err != nil {
		return errors.New("Youtube-dl pipe problem.")
	}

	ff := exec.Command("ffmpeg", "-i", "pipe:0", "-f", "s16le", "-ar", strconv.Itoa(frameRate), "-ac", strconv.Itoa(channels), "pipe:1")
	ff.Stdin = out
	musicStream, err := ff.StdoutPipe()
	if err != nil {
		return errors.New("FFMPEG pipe problem.")
	}

	err = youtubedl.Start()
	if err != nil {
		return errors.New("Command execution failed!")
	}
	fmt.Println("Youtube-DL started.")

	err = ff.Start()
	if err != nil {
		return errors.New("Command execution failed!")
	}
	fmt.Println("FFMPEG started.")

	ffmpegbuf := bufio.NewReaderSize(musicStream, 16384)

	// Send "speaking" packet over the voice websocket
	err = mp.voiceConn.Speaking(true)
	if err != nil {
		return errors.New("Cannot speak!")
	}
	// Send not "speaking" packet over the websocket when we finish
	err = mp.voiceConn.Speaking(false)

	send := make(chan []int16, 2)
	defer close(send)

	go dgvoice.SendPCM(mp.voiceConn, send)

	audiobuf := make([]int16, frameSize*channels)
	for {
		// read data from ffmpeg stdout
		err = binary.Read(ffmpegbuf, binary.LittleEndian, &audiobuf)
		if err == io.EOF || err == io.ErrUnexpectedEOF || err != nil {
			return err
		}

		if mp.next || mp.stop {
			mp.isPlaying = false
			mp.stop = true
			if err := mp.voiceConn.Disconnect(); err != nil {
				return err
			}
			break
		}

		send <- audiobuf
	}

	return nil
}
