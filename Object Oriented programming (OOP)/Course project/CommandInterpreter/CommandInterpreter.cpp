#include <algorithm>
#include "CommandInterpreter.h"

void toUpper(std::string &str) {
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        str[i] = toupper(str[i]);
    }
}

void removeWs(std::string &str) {
    if (str.length()) {
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    }
}

CommandInterpreter::CommandInterpreter(){
    fileOpenned = false;
};

void CommandInterpreter::parse(std::string rawCommand) {
    if (rawCommand.length() == 0) {
        throw std::invalid_argument("Empty command line!");
    }

    size_t len = rawCommand.length();
    std::string copyCommand = rawCommand;
    std::string token;
    size_t pos = 0;
    size_t quotePos = 0;

    while (true) {
        pos = copyCommand.find(' ');
        quotePos = copyCommand.find("\"");

        if (pos != std::string::npos) {
            if (quotePos > pos && quotePos != std::string::npos) {
                token = copyCommand.substr(0, pos);
                parsedCommand.push_back(token);
                copyCommand.erase(0, pos + 1);
            } else {
                if (quotePos != std::string::npos) {
                    copyCommand.erase(quotePos, quotePos + 1);

                    size_t tempQuotePos = copyCommand.find("\"");
                    token = copyCommand.substr(quotePos, tempQuotePos);

                    parsedCommand.push_back(token);
                    copyCommand.erase(0, tempQuotePos + 1);

                } else {
                    token = copyCommand.substr(0, pos);
                    removeWs(token);
                    if (token.length() > 0) {
                        parsedCommand.push_back(token);
                    }
                    copyCommand.erase(0, pos + 1);
                }
            }
        } else {
            if (copyCommand.length() > 0) {
                token = copyCommand.substr(0, copyCommand.length());
                parsedCommand.push_back(token);
            }

            break;
        }
    }
    removeWs(parsedCommand[0]); //remove all WS from first string because I need to compare it
    toUpper(parsedCommand[0]);

    try {
        decode(parsedCommand);
    } catch (const std::invalid_argument &ia) {
        std::cout << ia.what() << std::endl;
    }
}


void CommandInterpreter::decode(std::vector<std::string> &parsedCommand) {
    toUpper(parsedCommand[0]);
    if (parsedCommand[0] == "OPEN") {
        open(parsedCommand);
    } else if (parsedCommand[0] == "CLOSE") {
        //close(parsedCommand);
    } else if (parsedCommand[0] == "NEWFILE") {

    } else if (parsedCommand[0] == "SAVE") {

    } else if (parsedCommand[0] == "SAVEAS") {

    } else {
        throw std::invalid_argument("Invalid command!");
    }
}
