package main

import (
	"fmt"
	"strings"

	"github.com/bwmarrin/discordgo"
)

var (
	commands = []*discordgo.ApplicationCommand{
		{
			Name:        "voice-chat-top",
			Description: "Gives users who talked the most in the server for all times.",
		},
		{
			Name:        "talk-history",
			Description: "Command gives voice chat history for a given user.",
			Options: []*discordgo.ApplicationCommandOption{

				{
					Type:        discordgo.ApplicationCommandOptionString,
					Name:        "user",
					Description: "Username",
					Required:    true,
				},
			},
		},
		{
			Name:        "play",
			Description: "IntroToGo bot starts playing youtube song from given link.",
			Options: []*discordgo.ApplicationCommandOption{
				{
					Type:        discordgo.ApplicationCommandOptionString,
					Name:        "channel",
					Description: "Voice channel for the bot to enter",
					Required:    true,
				},
				{
					Type:        discordgo.ApplicationCommandOptionString,
					Name:        "url",
					Description: "Youtube song url",
					Required:    true,
				},
			},
		},
		{
			Name:        "stop",
			Description: "If there is music playing the command stops it.",
		},
	}

	commandsHandler = map[string]func(session *discordgo.Session, event *discordgo.InteractionCreate){
		"voice-chat-top": func(session *discordgo.Session, event *discordgo.InteractionCreate) {

			var sb strings.Builder
			if len(voiceStats) > 0 {
				top := make([]Pair, len(voiceStats))

				i := 0
				for key, value := range voiceStats {
					top[i] = Pair{key, value.secondsTalked}
					i++
				}

				SortBySecond(top)

				for count, item := range top {
					if strings.Compare(item.First, session.State.User.Username) != 0 {
						fmt.Fprintf(&sb, "%d : %s	%d seconds\n", count+1, item.First, item.Second)
					}
				}
			} else {
				sb.WriteString("No users talked.")
			}

			session.InteractionRespond(event.Interaction, &discordgo.InteractionResponse{
				Type: discordgo.InteractionResponseChannelMessageWithSource,
				Data: &discordgo.InteractionResponseData{
					Content: sb.String(),
				},
			})
		},
		"talk-history": func(s *discordgo.Session, i *discordgo.InteractionCreate) {
			// Access options in the order provided by the user.
			options := i.ApplicationCommandData().Options

			// Or convert the slice into a map
			optionMap := make(map[string]*discordgo.ApplicationCommandInteractionDataOption, len(options))
			for _, opt := range options {
				optionMap[opt.Name] = opt
			}

			var sb strings.Builder

			// When the option exists, ok = true
			if option, ok := optionMap["user"]; ok {
				sb.WriteString("Voice history for user: ")
				sb.WriteString(option.StringValue())
				sb.WriteString("\n")
				sb.WriteString(UserVoiceHistory(option.StringValue()))
			}

			s.InteractionRespond(i.Interaction, &discordgo.InteractionResponse{
				// Ignore type for now, they will be discussed in "responses"
				Type: discordgo.InteractionResponseChannelMessageWithSource,
				Data: &discordgo.InteractionResponseData{
					Content: sb.String(),
				},
			})
		},
		"play": func(s *discordgo.Session, i *discordgo.InteractionCreate) {
			// Access options in the order provided by the user.
			options := i.ApplicationCommandData().Options

			// Or convert the slice into a map
			optionMap := make(map[string]*discordgo.ApplicationCommandInteractionDataOption, len(options))
			for _, opt := range options {
				optionMap[opt.Name] = opt
			}

			var sb strings.Builder

			if mp.isPlaying {
				sb.WriteString("🔸Song is already going!\n")
			}

			// When the option exists, ok = true
			channelopt, ok := optionMap["channel"]
			if !ok {
				sb.WriteString("🔸Not valid channel!\n")
			}

			urlopt, ok := optionMap["url"]
			if !ok {
				sb.WriteString("🔸Not valid url!\n")
			}

			found := GetChannel(i.GuildID, channelopt.StringValue())
			if found == nil {
				sb.WriteString("🔸Channel not found")
			}

			if sb.Len() == 0 {
				sb.WriteString("🔊  Playing: ")
				sb.WriteString(urlopt.StringValue())
				sb.WriteString("\n")
				go func() {
					err := discordPlayMusic(i.GuildID, found.ID, urlopt.StringValue())
					mp.voiceConn.Disconnect()
					fmt.Println(err)
				}()
			}

			s.InteractionRespond(i.Interaction, &discordgo.InteractionResponse{
				// Ignore type for now, they will be discussed in "responses"
				Type: discordgo.InteractionResponseChannelMessageWithSource,
				Data: &discordgo.InteractionResponseData{
					Content: sb.String(),
				},
			})
		},
		"stop": func(s *discordgo.Session, i *discordgo.InteractionCreate) {

			var sb strings.Builder
			if !mp.isPlaying {
				sb.WriteString("🔸There is no song playing!\n")
			} else {
				sb.WriteString("🔸Song stopped.\n")
			}

			mp.isPlaying = false
			mp.stop = true

			s.InteractionRespond(i.Interaction, &discordgo.InteractionResponse{
				// Ignore type for now, they will be discussed in "responses"
				Type: discordgo.InteractionResponseChannelMessageWithSource,
				Data: &discordgo.InteractionResponseData{
					Content: sb.String(),
				},
			})
		},
	}
)

func createCommands() {
	len := len(commands)

	fmt.Printf("Register %d commands.\n", len)

	for i := 0; i < len; i++ {
		ccmd, err := session.ApplicationCommandCreate(session.State.User.ID, *GuildID, commands[i])
		if err != nil {
			fmt.Printf("%s failed registering with error %d.", ccmd.Name, err)
		}
	}
}

func addHandlersToCommands() {
	len := len(commandsHandler)
	fmt.Printf("Add %d command handlers.\n", len)

	session.AddHandler(func(s *discordgo.Session, i *discordgo.InteractionCreate) {
		if cmd, ok := commandsHandler[i.ApplicationCommandData().Name]; ok {
			cmd(s, i)
		}
	})
}
