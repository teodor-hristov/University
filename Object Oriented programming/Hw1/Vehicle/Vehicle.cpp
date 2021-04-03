#include "Vehicle.hpp"

Vehicle::Vehicle(const char *registration, const char *description, std::size_t space) {
    MyString regN = MyString(registration);
    MyString dsc = MyString(registration);
    this->regNumber = regN;
    this->desc = dsc;
    this->parkingSize = space;

}

const char *Vehicle::registration() const {
    return this->regNumber.c_str();
}

const char *Vehicle::description() const {
    return this->desc.c_str();
}

std::size_t Vehicle::space() const {
    return this->parkingSize;
}
