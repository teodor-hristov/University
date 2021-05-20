#include <vector>
#include "CommandInterpeter.h"
#include <algorithm>

void toUpper(std::string &str) {
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        str[i] = toupper(str[i]);
    }
}

CommandInterpreter::CommandInterpreter(std::vector<Registration *> &regs,
                                       std::vector<Vehicle *> &vehicles,
                                       std::vector<Person *> &people) {
    this->vehicles = &vehicles;
    this->people = &people;
    this->regs = &regs;
}

void CommandInterpreter::interpret(std::string commandLine) {
    std::vector<std::string> commandParts;
    size_t pos = 0;
    std::string token;

    while (true) {
        if ((pos = commandLine.find('"')) !=
            std::string::npos) { //There is only one way to find ". If and if only the name of the person is made from 2 parts (like "Ivan Ivanov")
            token = commandLine.substr(0, pos);
            commandParts.push_back(token);
            commandLine.erase(0, pos + 1);
        } else {
            if ((pos = commandLine.find(' ')) != std::string::npos) {
                token = commandLine.substr(0, pos);
                commandLine.erase(0, pos + 1);

                if (pos != 0) { //don't need only WS
                    commandParts.push_back(token);
                }
            } else { //Push the rest of the command
                token = commandLine.substr(0, commandLine.length());
                commandParts.push_back(token);

                break;

            }
        }
    }
    removeWs(commandParts[0]); //remove all WS from first string because I need to compare it
    toUpper(commandParts[0]);

    route(commandParts);
}


void CommandInterpreter::removeWs(std::string &str) {
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
}

void CommandInterpreter::route(std::vector<std::string> &args) {
    if (args[0] == "VEHICLE") {
        createVehicle(args);
    } else if (args[0] == "PERSON") {
        createPerson(args);
    } else if (args[0] == "ACQUIRE") {
        acquire(args);
    } else if (args[0] == "RELEASE") {
        release(args);
    } else if (args[0] == "REMOVE") {
        remove(args);
    } else if (args[0] == "SAVE") {
        //VEHICLE
    } else if (args[0] == "SHOW") {
        //VEHICLE
    } else {
        throw std::invalid_argument("Invalid argument!");
    }

}

void CommandInterpreter::createVehicle(const std::vector<std::string> &args) {
    std::cout << "CommandInterpreter::createVehicle" << "\n";

    if (args.size() != 3) { //VEHICLE <registration> <description>
        std::cout << "Invalid command VEHICLE." << "\n";
        throw std::invalid_argument("Wrong function format!");
    }

    Registration *reg = new Registration(args[1]);
    if (Registration::registrationExists(*reg, regs)) {
        delete reg; //now the registration is invalid and there is no need of this pointer
        throw std::invalid_argument("Registration already exists.");
    }

    Vehicle *vhcl = new Vehicle(reg, args[2]);

    regs->push_back(reg);
    vehicles->push_back(vhcl);

}

void CommandInterpreter::createPerson(const std::vector<std::string> &args) {
    std::cout << "CommandInterpreter::createPerson" << "\n";
    unsigned id;
    if (args.size() != 3) { //PERSON <name> <id>
        std::cout << "Invalid command PERSON." << "\n";
        throw std::invalid_argument("Wrong function format!");
    }

    id = strtoul(args[2].c_str(), nullptr, 0);

    if (Person::idExits(id, people)) {
        throw std::invalid_argument("Person is already born.");
    }

    Person *p = new Person(args[1], id);

    people->push_back(p);

}

void CommandInterpreter::acquire(std::vector<std::string> &args) {
    std::cout << "CommandInterpreter::acquire" << "\n";
    unsigned id;

    if (args.size() != 3) { //ACQUIRE <owner-id> <vehicle-id>
        std::cout << "Invalid command ACQUIRE." << "\n";
        throw std::invalid_argument("Wrong function format!");
    }

    id = strtoul(args[1].c_str(), nullptr, 0);

    Vehicle *wantedVehicle = Vehicle::findById(args[2], vehicles);
    if (!wantedVehicle) {
        throw std::invalid_argument("Vehicle with this type of registration does not exist!");
    }

    Person *wantedPerson = Person::findById(id, people);
    if (!wantedPerson) {
        throw std::invalid_argument("Person does not exist!");
    }

    wantedPerson->addVehicle(wantedVehicle);
}

void CommandInterpreter::release(std::vector<std::string> &args) {
    std::cout << "CommandInterpreter::release" << "\n";
    unsigned id;

    if (args.size() != 3) { //RELEASE <owner-id> <vehicle-id>
        std::cout << "Invalid command RELEASE." << "\n";
        throw std::invalid_argument("Wrong function format!");
    }

    id = strtoul(args[1].c_str(), nullptr, 0);

    Vehicle *wantedVehicle = Vehicle::findById(args[2], vehicles);
    if (!wantedVehicle) {
        throw std::invalid_argument("Vehicle with this type of registration does not exist!");
    }

    Person *wantedPerson = Person::findById(id, people);
    if (!wantedPerson) {
        throw std::invalid_argument("Person does not exist!");
    }

    wantedPerson->removeVehicle(wantedVehicle);
}

void CommandInterpreter::remove(const std::vector<std::string> &args) {
    unsigned id;
    Vehicle *wantedVehicle;
    Person *wantedPerson;

    std::cout << "CommandInterpreter::remove" << "\n";

    if (args.size() != 2) {
        std::cout << "Invalid command REMOVE." << "\n";
        throw std::invalid_argument("Wrong function format!");
    }

    if (Registration::isNumberValid(args[1])) {
        wantedVehicle = Vehicle::findById(const_cast<std::string &>(args[1]), vehicles);
        if (wantedVehicle) {
            std::cout << "Namerih go brat karucata.\n";
            //todo confirmation
            wantedVehicle->removeOwner();
            purge(wantedVehicle);
        }
    }

    id = strtoul(args[1].c_str(), nullptr, 0);
    wantedPerson = Person::findById(id, people);
    if (wantedPerson) {
        std::cout << "Namerih go brat choveka.\n";
        //todo confirmation
        purge(wantedPerson);
    }
}

void CommandInterpreter::purge(Vehicle *wantedVehicle) {
    std::size_t len = vehicles->size();

    for (int i = 0; i < len; ++i) {
        if ((*vehicles)[i] == wantedVehicle) {

            delete wantedVehicle;
            vehicles->erase(this->vehicles->begin() + i);

        }
    }
}

void CommandInterpreter::purge(Person *wantedPerson) {
    std::size_t len = people->size();
    std::size_t vhclsLen = wantedPerson->getVehicles().size();

    for (int i = 0; i < vhclsLen; ++i) {
        wantedPerson->removeVehicle(wantedPerson->getVehicles()[i]);
    }

    for (int i = 0; i < len; ++i) {
        if ((*people)[i] == wantedPerson) {

            delete wantedPerson;
            people->erase(this->people->begin() + i);

        }
    }
}






