package main

import (
	"errors"
	"os/exec"
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

func getSongName(url string) (string, error) {
	youtubedl := exec.Command("yt-dlp", "--get-title", url, "-o", "-")
	out, err := youtubedl.CombinedOutput()

	if err != nil {
		return "", errors.New("Youtube-dl pipe problem.")
	}

	defer youtubedl.Process.Kill()
	youtubedl.Wait()

	return string(out), nil
}
