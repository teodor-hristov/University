#include "../Vehicle/Vehicle.hpp"
#include "Garage.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

Garage::Garage(std::size_t size) {
    assert(size >= 0);
    this->vhcls = new Vehicle *[size];
    assert(vhcls != nullptr);
    this->usedSpots = 0;
    this->lastIndex = 0;
    this->spots = size;

}

Garage::Garage(const Garage &garage) {
    this->vhcls = new Vehicle *[garage.size()];
    this->spots = garage.spots;
    this->lastIndex = garage.lastIndex;
    this->usedSpots = garage.usedSpots;
    assert(this->vhcls != nullptr);
    memcpy(this->vhcls, garage.vhcls, garage.size());
}

Garage::~Garage() {
    delete[] this->vhcls;
}

Garage &Garage::operator=(const Garage &garage) {
    if (this->vhcls) {
        delete[] this->vhcls;
    }
    if (this != &garage) {
        this->vhcls = new Vehicle *[garage.size()];
        assert(this->vhcls != nullptr);

        for (int i = 0; i < garage.lastIndex; ++i) {
            this->vhcls[i] = garage.vhcls[i];
        }

        this->spots = garage.spots;
        this->lastIndex = garage.lastIndex;
        this->usedSpots = garage.usedSpots;
    }

    return *this;
}

void Garage::insert(Vehicle &v) {
    if (v.space() + this->usedSpots > this->size()) {
        throw std::out_of_range("Not enough space for this vehicle.");
    }
    if (this->find(v.registration()) != nullptr) {
        throw std::invalid_argument("Invalid index.");
    }

    this->usedSpots += v.space();
    this->vhcls[lastIndex] = &v;
    this->lastIndex++;
}

int findVehicle(const Garage *garage, const char *vhcl) {
    for (int i = 0; i < garage->size(); ++i) {
        if (strcmp(garage->at(i).registration(), vhcl) == 0) {
            return i;
        }
    }

    return -1;
}

void Garage::erase(const char *registration) {
    if (this->lastIndex == 0) {
        return;
    }
    int vhclIndex = findVehicle(this, registration);
    this->usedSpots -= this->vhcls[vhclIndex]->space();

    //here we don't want to delete the car from the memory, we just need to remove it from the array a.k.a. garage.vhcls
    if (vhclIndex >= 0) {
        for (int i = vhclIndex; i < this->lastIndex; ++i) {
            this->vhcls[i] = this->vhcls[i + 1];
        }

        this->vhcls[this->lastIndex] = nullptr;
        this->lastIndex--;
    }
}

bool Garage::empty() const {
    return !this->spots;
}

std::size_t Garage::size() const {
    return this->spots;
}

void Garage::clear() {
    for (int i = 0; i < lastIndex; ++i) {
        this->vhcls[i] = nullptr;
    }
}

Vehicle *Garage::find(const char *registration) {
    // We need to count not the cars but the spots
    for (size_t i = 0; i < lastIndex; ++i) {
        if (strcmp((*this->vhcls[i]).registration(), registration) == 0) {
            return this->vhcls[i];
        }

    }

    return nullptr;
}

const Vehicle *Garage::find(const char *registration) const {
    // We need to count not the cars but the spots

    for (size_t i = 0; i < lastIndex; ++i) {
        if ((*this->vhcls[i]).registration() == registration) {
            return this->vhcls[i];
        }
    }

    return nullptr;
}

Vehicle &Garage::at(std::size_t pos) {
    assert(pos >= 0 && pos < this->size());
    return *this->vhcls[pos];
}

const Vehicle &Garage::at(std::size_t pos) const {
    assert(pos >= 0 && pos < this->size());
    return *this->vhcls[pos];
}

Vehicle &Garage::operator[](std::size_t pos) {
    assert(pos >= 0 && pos < this->size());
    return *this->vhcls[pos];
}

const Vehicle &Garage::operator[](std::size_t pos) const {
    assert(pos >= 0 && pos < this->size());
    return *this->vhcls[pos];
}

size_t Garage::getLastIndex() const {
    return this->lastIndex;
}
