#pragma once
#include "../Vehicle/Vehicle.hpp"

class Garage{
private:
    std::size_t spots;
    std::size_t usedSpots;
    std::size_t lastIndex;
    Vehicle** vhcls;
public:
    Garage(std::size_t size); //max parking spots - size
    Garage(const Garage &garage);
    ~Garage();
    Garage& operator=(Garage &garage);
    void insert(Vehicle& v);
    void erase(const char* registration);
    Vehicle& at(std::size_t pos);
    const Vehicle& at(std::size_t pos) const;
    Vehicle& operator[](std::size_t pos);
    const Vehicle& operator[](std::size_t pos) const;
    bool empty() const;
    std::size_t size() const;
    void clear();
    Vehicle* find(const char* registration);
    const Vehicle* find(const char* registration) const;

    size_t getLastIndex() const;
};