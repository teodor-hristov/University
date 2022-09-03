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
	guildId       string
	timeJoined    []time.Time
	timeLeft      []time.Time
}

var voiceStats = make(map[string]map[string]Statistics)

func UserJoined(event *discordgo.VoiceStateUpdate) {
	if event == nil {
		return
	}

	userName := event.Member.User.Username
	entry := voiceStats[event.GuildID][userName]

	entry.isTalking = true
	entry.timeJoined = append(entry.timeJoined, time.Now())
	entry.channelID = event.ChannelID

	voiceStats[event.GuildID][userName] = entry

	fmt.Printf("User joined %s %s\n", userName, voiceStats[event.GuildID][userName].timeJoined[len(voiceStats[event.GuildID][userName].timeJoined)-1].String())
}

func UserLeft(event *discordgo.VoiceStateUpdate) {
	if event == nil {
		return
	}

	userName := event.Member.User.Username

	entry := voiceStats[event.GuildID][userName]

	entry.isTalking = false
	entry.timeLeft = append(entry.timeLeft, time.Now())

	//the only reason for len(voiceStats[event.GuildID][userName].timeJoined) to be 0 is when bot is after the other person (who left)
	if len(voiceStats[event.GuildID][userName].timeJoined) == 0 {
		entry.timeJoined = append(voiceStats[event.GuildID][session.State.User.Username].timeJoined)
	}
	//entry.channelID = event.ChannelID on leave no channelID is given
	entry.secondsTalked += uint64(time.Now().Sub(entry.timeJoined[len(entry.timeJoined)-1]).Abs().Seconds())

	voiceStats[event.GuildID][userName] = entry

	//if bot is disconnected while playing -> turn off the music
	if strings.Compare(userName, session.State.User.Username) == 0 {
		entry := mp[event.GuildID]
		entry.isPlaying = false
		mp[event.GuildID] = entry
	}

	fmt.Printf("User left voice channel %s %s\nTotal talking time %d seconds\n",
		userName,
		voiceStats[event.GuildID][userName].timeLeft[len(voiceStats[event.GuildID][userName].timeLeft)-1].String(),
		voiceStats[event.GuildID][userName].secondsTalked)
}

func UserVoiceHistory(guildId string, userName string) string {
	var res strings.Builder

	minStats := int(math.Min(float64(len(voiceStats[guildId][userName].timeJoined)), float64(len(voiceStats[guildId][userName].timeLeft))))
	delta := len(voiceStats[guildId][userName].timeJoined) - len(voiceStats[guildId][userName].timeLeft)

	for i := 0; i < minStats; i++ {
		res.WriteString("Joined at: ")
		res.WriteString(voiceStats[guildId][userName].timeJoined[i].String())
		res.WriteString("\n")

		res.WriteString("Left at: ")
		res.WriteString(voiceStats[guildId][userName].timeLeft[i].String())
		res.WriteString("\n")
	}

	if delta > 0 {
		res.WriteString("Joined at: ")
		res.WriteString(voiceStats[guildId][userName].timeJoined[len(voiceStats[guildId][userName].timeJoined)-1].String())
		res.WriteString("\n")
	}

	return res.String()
}
