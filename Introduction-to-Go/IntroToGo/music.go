package main

import (
	"bufio"
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

/*Map GuildID to MP*/
var mp = make(map[string]*MusicPlayer)

type MusicPlayer struct {
	voiceConn *discordgo.VoiceConnection
	isPlaying bool
}

func discordPlayMusic(guildId string, channelId string, songUrl string) error {
	if len(guildId) == 0 || len(channelId) == 0 || len(songUrl) == 0 {
		return errors.New("Invalid input!")
	}

	voiceConn, err := session.ChannelVoiceJoin(guildId, channelId, false, false)
	if err != nil {
		return err
	}

	if mp[guildId] == nil {
		mp[guildId] = new(MusicPlayer)
	}

	mp[guildId].isPlaying = true
	mp[guildId].voiceConn = voiceConn

	if mp[guildId].voiceConn.Ready {
		return playSong(songUrl, mp[guildId])
	}

	return errors.New("Problem finding connecting.")
}

func playSong(songUrl string, mp *MusicPlayer) error {
	if mp == nil || mp.voiceConn == nil {
		return errors.New("voiceConnection error")
	}
	_, err := url.Parse(songUrl)
	if err != nil {
		return errors.New("Url is not valid.")
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
	defer youtubedl.Process.Kill()

	err = ff.Start()
	if err != nil {
		return errors.New("Command execution failed!")
	}
	fmt.Println("FFMPEG started.")
	defer ff.Process.Kill()

	ffmpegbuf := bufio.NewReaderSize(musicStream, 16384)

	// Send "speaking" packet over the voice websocket
	err = mp.voiceConn.Speaking(true)
	if err != nil {
		return errors.New("Cannot speak!")
	}

	send := make(chan []int16, channels)
	defer close(send)

	go dgvoice.SendPCM(mp.voiceConn, send)

	audiobuf := make([]int16, frameSize*channels)
	for {
		// read data from ffmpeg stdout
		err = binary.Read(ffmpegbuf, binary.LittleEndian, &audiobuf)

		if !mp.isPlaying || err == io.EOF || err == io.ErrUnexpectedEOF || err != nil {
			mp.isPlaying = false
			// Send not "speaking" packet over the websocket when we finish
			mp.voiceConn.Speaking(false)

			break
		}

		send <- audiobuf
	}

	return nil
}
