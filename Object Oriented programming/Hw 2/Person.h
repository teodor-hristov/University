#ifndef HW_2_PERSON_H
#define HW_2_PERSON_H

#pragma once
#include <string>
#include <vector>


class Vehicle;

class Person{
private:
    unsigned int id;
    std::string name;
    std::vector<Vehicle*> vehicles;

public:
    explicit Person(const std::string& name);

    void addVehicle(Vehicle& vhcl);

    const std::string &getName() const;

    const std::vector<Vehicle*> &getVehicles() const;
};

#endif