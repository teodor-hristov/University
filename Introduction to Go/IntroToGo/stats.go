package main

import (
	"fmt"
	"math"
	"strings"
	"time"

	"github.com/bwmarrin/discordgo"
)

type Statistics struct {
	isTalking     bool
	secondsTalked uint64
	channelID     string
	timeJoined    []time.Time
	timeLeft      []time.Time
}

var voiceStats = make(map[string]Statistics)

func UserJoined(event *discordgo.VoiceStateUpdate) {
	if event == nil {
		return
	}

	userName := event.Member.User.Username

	entry := voiceStats[userName]

	entry.isTalking = true
	entry.timeJoined = append(entry.timeJoined, time.Now())
	entry.channelID = event.ChannelID

	voiceStats[userName] = entry

	fmt.Printf("User joined %s %s\n", userName, voiceStats[userName].timeJoined[len(voiceStats[userName].timeJoined)-1].String())
}

func UserLeft(event *discordgo.VoiceStateUpdate) {
	if event == nil {
		return
	}

	userName := event.Member.User.Username

	entry := voiceStats[userName]

	entry.isTalking = false
	entry.timeLeft = append(entry.timeLeft, time.Now())

	//the only reason for len(voiceStats[userName].timeJoined) to be 0 is when bot is after the other person (who left)
	if len(voiceStats[userName].timeJoined) == 0 {
		entry.timeJoined = append(voiceStats[session.State.User.Username].timeJoined)
	}
	//entry.channelID = event.ChannelID on leave no channelID is given
	entry.secondsTalked += uint64(time.Now().Sub(entry.timeJoined[len(entry.timeJoined)-1]).Abs().Seconds())

	voiceStats[userName] = entry

	//if bot is disconnected while playing -> turn off the music
	if strings.Compare(event.UserID, session.State.User.Username) == 0 {
		mp.isPlaying = false
	}

	fmt.Printf("User left voice channel %s %s\nTotal talking time %d seconds\n",
		userName,
		voiceStats[userName].timeLeft[len(voiceStats[userName].timeLeft)-1].String(),
		voiceStats[userName].secondsTalked)
}

func UserVoiceHistory(userName string) string {
	var res strings.Builder

	minStats := int(math.Min(float64(len(voiceStats[userName].timeJoined)), float64(len(voiceStats[userName].timeLeft))))
	delta := len(voiceStats[userName].timeJoined) - len(voiceStats[userName].timeLeft)

	for i := 0; i < minStats; i++ {
		res.WriteString("Joined at: ")
		res.WriteString(voiceStats[userName].timeJoined[i].String())
		res.WriteString("\n")

		res.WriteString("Left at: ")
		res.WriteString(voiceStats[userName].timeLeft[i].String())
		res.WriteString("\n")
	}

	if delta > 0 {
		res.WriteString("Joined at: ")
		res.WriteString(voiceStats[userName].timeJoined[len(voiceStats[userName].timeJoined)-1].String())
		res.WriteString("\n")
	}

	return res.String()
}
