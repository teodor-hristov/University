#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(const Registration *registration, const std::string &desc) : registration(*registration) {
    description = desc;
    owner = nullptr;
}

const Registration &Vehicle::getRegistration() const {
    return registration;
}

const std::string &Vehicle::getDescription() const {
    return description;
}

const Person *Vehicle::getOwner() const {
    return owner;
}

void Vehicle::setOwner(Person *value) {
    this->owner = value;
}

Vehicle *Vehicle::findById(std::string &id, std::vector<Vehicle *>* vect) {
    std::size_t len = vect->size();
    for (int i = 0; i < len; ++i) {
        if ((*vect)[i]->registration.getRegistrationNumber() == id) {
            return (*vect)[i];
        }
    }

    return nullptr;
}

std::ostream &operator<<(std::ostream &out, const Vehicle &vhcl) {
    out << vhcl.registration.getRegistrationNumber() << std::endl << vhcl.owner->getName() << std::endl
        << vhcl.description << std::endl;
    return out;
}

void Vehicle::removeOwner() {
    if (this->owner) {
        this->owner->removeVehicle(this);
        this->owner = nullptr;
    }
}
