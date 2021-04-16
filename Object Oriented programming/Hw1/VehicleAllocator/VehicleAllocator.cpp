#include "VehicleAllocator.hpp"
#include <cstring>
#include <cassert>
#include <iostream>

VehicleAllocator::VehicleAllocator() {
    container = new Vehicle *[2];
    size = 2;
    lastIndex = 0;
}

void VehicleAllocator::addVehicle(Vehicle &vhcl) {
    if (lastIndex + 1 == size) {
        resize();
    }

    container[lastIndex] = &vhcl;
    lastIndex++;
}

void VehicleAllocator::resize() {
    Vehicle **temp = new Vehicle *[size * 2];
    assert(temp);

    for (int i = 0; i < lastIndex; ++i) {
        temp[i] = container[i];
    }

    size = size * 2;
    delete[] container;
    container = temp;
}


Vehicle *VehicleAllocator::createVehicle(Garage &garage) {
    int spots;
    char registration[128], description[128];
    Vehicle *vhcl;

    std::cout << "Enter registration:" << std::endl;
    std::cin.ignore();
    std::cin.getline(registration, 128);

    std::cout << "Enter description:" << std::endl;
    std::cin.ignore();
    std::cin.getline(description, 128);

    std::cout << "Enter car size:" << std::endl;
    std::cin >> spots;

    vhcl = new Vehicle(registration, description, spots);

    addVehicle(*vhcl);

    return vhcl;
}

VehicleAllocator::~VehicleAllocator() {
    for (int i = 0; i < lastIndex; ++i) {
        delete this->container[i];
    }

    this->lastIndex = 0;
    this->size = 0;
    delete[] container;
}
