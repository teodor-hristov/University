#pragma once

#include "../MyString/MyString.hpp"

class Vehicle{
private:
    MyString regNumber;
    MyString desc;
    std::size_t parkingSize;
public:
    Vehicle(const char* registration, const char* description, std::size_t space);
    const char* registration() const;
    const char* description() const;
    std::size_t space() const;

};