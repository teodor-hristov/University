package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/bwmarrin/discordgo"
)

var (
	BotToken = flag.String("token", "", "Bot access token")
	session  *discordgo.Session
)

func init() {
	flag.Parse()

	connectToDiscord()

	for _, item := range session.State.Guilds {
		voiceStats[item.ID] = make(map[string]Statistics)
	}
}

func addIntents() {
	session.Identify.Intents = discordgo.MakeIntent(discordgo.IntentsAll)
}

func addHandlers() {
	addHandlersToCommands()

	session.AddHandler(voiceStatusUpdate)
}

func voiceStatusUpdate(session *discordgo.Session, event *discordgo.VoiceStateUpdate) {
	if event.ChannelID != "" {
		UserJoined(event)
		return
	}

	UserLeft(event)
}

func connectToDiscord() {
	//Connect to discord
	var err error
	session, err = discordgo.New("Bot MTAxMzc5Mjg4NTE4MDczOTcxNA.GQKXEe.JP-GAfwvafqbNucRO235AR7ZW2alIm1kRgeA2A")
	if err != nil {
		log.Fatalf("Invalid bot parameters: %v", err)
		return
	}
	fmt.Print("Instance created.\n")

	err = session.Open()
	if err != nil {
		log.Fatalf("Connection open error: %v", err)
		return
	}
	fmt.Print("Connection created.\n")
	startTime = time.Now()
}

func disconnectFromDiscord() {
	session.Close()
	fmt.Print("Connection closed.\n")
}

func main() {
	addHandlers()
	addIntents()

	createCommands()

	// Wait here until CTRL-C or other term signal is received.
	fmt.Println("----------------------------\nPesho is now running.  Press CTRL-C to exit.\n----------------------------")

	//playSong("https://www.youtube.com/watch?v=VLjsoj1MnWA&list=RDBn2D_OYKF24&index=2")
	stopBot := make(chan os.Signal, 1)
	signal.Notify(stopBot, syscall.SIGINT, syscall.SIGTERM, os.Interrupt, os.Kill)
	<-stopBot

	// Cleanly close down the Discord session.
	disconnectFromDiscord()

	/*
		go build main.go music.go stats.go utils.go commands.go
		./main.exe -token=MTAxMzc5Mjg4NTE4MDczOTcxNA.GQKXEe.JP-GAfwvafqbNucRO235AR7ZW2alIm1kRgeA2A
	*/
}
