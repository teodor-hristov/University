#ifndef COURSE_PROJECT_COMMANDINTERPRETER_H
#define COURSE_PROJECT_COMMANDINTERPRETER_H

#include <iostream>
#include <string>
#include <vector>

class CommandInterpreter{
private:
    std::vector<std::string> parsedCommand;
    bool fileOpenned;

    void decode(std::vector<std::string>& parsedCommand);

    void open(const std::vector<std::string>& parsedCommand);
    void close(const std::vector<std::string>& parsedCommand);
    void newFile(const std::vector<std::string>& parsedCommand);
    void save(const std::vector<std::string>& parsedCommand);
    void saveAs(const std::vector<std::string>& parsedCommand);

public:
    explicit CommandInterpreter();

    void parse(std::string rawCommand);

    const std::string &getRawCommand() const;
};

#endif //COURSE_PROJECT_COMMANDINTERPRETER_H
