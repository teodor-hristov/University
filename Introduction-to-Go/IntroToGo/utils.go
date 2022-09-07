package main

import (
	"sort"
	"strings"

	"github.com/bwmarrin/discordgo"
)

type Pair struct {
	First  string
	Second uint64
}

func SortBySecond(users []Pair) {
	sort.SliceStable(users, func(i, j int) bool {
		return users[i].Second >= users[j].Second
	})
}

func GetChannel(guildId string, channelid string) *discordgo.Channel {
	gc, err := session.GuildChannels(guildId)
	if err != nil {
		return nil
	}

	for _, i := range gc {
		if i.Type == discordgo.ChannelTypeGuildVoice && strings.Compare(i.Name, channelid) == 0 {
			return i
		}
	}

	return nil
}
