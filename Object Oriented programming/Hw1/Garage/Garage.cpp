#include "../Vehicle/Vehicle.hpp"
#include "Garage.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

Garage::Garage(std::size_t size) {
    this->vhcls = new Vehicle*[size];
    assert(vhcls != nullptr);
    this->usedSpots = 0;
    this->lastIndex = 0;
    this->spots = size;

}

Garage::Garage(const Garage &garage) {
    this->vhcls = new Vehicle*[garage.size()];
    this->spots = garage.spots;
    this->lastIndex = garage.lastIndex;
    this->usedSpots = garage.usedSpots;
    assert(this->vhcls != nullptr);
    memcpy(this->vhcls, garage.vhcls, garage.size());
}

Garage::~Garage() {
    if(vhcls){
        delete[] this->vhcls;
    }
}

Garage &Garage::operator=(Garage &garage) {
    if(this->vhcls){
        delete[] this->vhcls;
    }
    if(this != &garage){
        this->vhcls = new Vehicle*[garage.size()];
        assert(this->vhcls != nullptr);

        this->vhcls = garage.vhcls;

        this->spots = garage.spots;
        this->lastIndex = garage.lastIndex;
        this->usedSpots = garage.usedSpots;
    }
}

void Garage::insert(Vehicle &v) {
    if(v.space() + this->usedSpots > this->size()) {
        throw std::out_of_range("");
    }
    if(this->find(v.registration()) != nullptr) {
        throw std::invalid_argument("");
    }

    this->usedSpots += v.space();
    this->vhcls[lastIndex] = &v;
    this->lastIndex++;

}

void Garage::erase(const char *registration) {

}

bool Garage::empty() const {
    return !this->spots;
}

std::size_t Garage::size() const {
    return this->spots;
}

void Garage::clear() {

}

Vehicle *Garage::find(const char *registration) {
   // We need to count not the cars but the spots

    for (size_t i = 0; i < lastIndex ;++i) {
        if((*this->vhcls[i]).registration() == registration){
            return this->vhcls[i];
        }
    }

    return nullptr;
}

const Vehicle *Garage::find(const char *registration) const {
    // We need to count not the cars but the spots

    for (size_t i = 0; i < lastIndex ;++i) {
        if((*this->vhcls[i]).registration() == registration){
            return this->vhcls[i];
        }
    }

    return nullptr;
}

Vehicle &Garage::at(std::size_t pos) {
    assert(pos >=0 && pos < this->size());
    return *this->vhcls[pos];
}

const Vehicle &Garage::at(std::size_t pos) const {
    assert(pos >=0 && pos < this->size());
    return *this->vhcls[pos];
}

Vehicle &Garage::operator[](std::size_t pos) {
    assert(pos >=0 && pos < this->size());
    return *this->vhcls[pos];
}

const Vehicle &Garage::operator[](std::size_t pos) const {
    assert(pos >= 0 && pos < this->size());
    return *this->vhcls[pos];
}

