#include "Vehicle.h"

Vehicle::Vehicle(const Registration &registration, const std::string& desc) : registration(registration){
    description = desc;
}

const Registration &Vehicle::getRegistration() const {
    return registration;
}

const std::string &Vehicle::getDescription() const {
    return description;
}

const Person* Vehicle::getOwner() const {
    return owner;
}

void Vehicle::setOwner(Person& owner) {
    Vehicle::owner = &owner;
}