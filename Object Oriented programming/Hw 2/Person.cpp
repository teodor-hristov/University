#include "Person.h"

Person::Person(const std::string &name) : name(name) {
}

void Person::addVehicle(Vehicle& vhcl) {
    vehicles.push_back(&vhcl);
}

const std::string &Person::getName() const {
    return name;
}

const std::vector<Vehicle *> &Person::getVehicles() const {
    return vehicles;
}


