#pragma once
#include "../Vehicle/Vehicle.hpp"
#include "../Garage/Garage.hpp"

class VehicleAllocator{
private:
    Vehicle** container;
    int lastIndex;
    int size;
    void resize();
public:

    Vehicle* createVehicle(Garage &garage);
    void addVehicle(Vehicle &vhcl);

    VehicleAllocator();
    ~VehicleAllocator();
};