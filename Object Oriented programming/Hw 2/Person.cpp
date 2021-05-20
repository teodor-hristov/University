#include <iostream>
#include "Person.h"
#include "Vehicle.h"

Person::Person(const std::string &name, unsigned int id) : name(name), id(id) {
}

void Person::addVehicle(Vehicle *vhcl) {
    if (vhcl->getOwner()) {
        if (vhcl->getOwner()->id != this->id) {
            vehicles.push_back(vhcl);
            vhcl->setOwner(this);
        }
    } else {
        vehicles.push_back(vhcl);
        vhcl->setOwner(this);
    }

}

const std::string &Person::getName() const {
    return name;
}

const std::vector<Vehicle *> &Person::getVehicles() const {
    return vehicles;
}

void Person::printCars() {
    int size = this->vehicles.size();
    for (int i = 0; i < size; ++i) {
        std::cout << i << ". " << (*vehicles[i]);
    }
}

void Person::removeVehicle(Vehicle *vehicle) {
    int len = vehicles.size();

    for (int i = 0; i < len; ++i) {
        if (this->vehicles[i] == vehicle) {
            this->vehicles[i]->setOwner(nullptr);
            this->vehicles.erase(this->vehicles.begin() + i);
        }
    }

}

bool Person::idExits(unsigned int id, std::vector<Person *>* vect) {
    int len = vect->size();
    for (int i = 0; i < len; ++i) {
        if ((*vect)[i]->id == id) { return true; }
    }

    return false;
}

std::ostream &operator<<(std::ostream &out, Person &person) {
    std::size_t len = person.vehicles.size();
    out << "Id: " << person.id << " \nName: " << person.name << "\nCars: " << person.vehicles.size();

    //person.printCars();

    return out;
}

Person *Person::findById(unsigned int id, std::vector<Person *>* vect) {
    std::size_t len = vect->size();
    for (int i = 0; i < len; ++i) {
        if ((*vect)[i]->id == id) { return (*vect)[i]; }
    }

    return nullptr;
}


