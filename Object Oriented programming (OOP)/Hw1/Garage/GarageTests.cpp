#pragma once
#include "Garage.hpp"
#include "../catch_amalgamated.hpp"

bool areCarsEqual(const Vehicle &v1, const Vehicle &v2){
    return (v1.space() == v2.space()) && !strcmp(v1.registration(), v2.registration()) && !strcmp(v1.description(), v2.description());
}

TEST_CASE("Copy ctor"){
    Garage garage1 = Garage(7);
    Vehicle* car = new Vehicle("Algebra", "will tell you", 1);
    garage1.insert(*car);

    Garage garage2 = garage1;

    REQUIRE(garage2.size() == garage1.size());
    REQUIRE(areCarsEqual(garage2[0],garage1[0]));

    delete car;
}

TEST_CASE("Test Garage.insert() with normal values"){
    Garage garage = Garage(2);
    Vehicle* vhcl = new Vehicle("asdsad", "asdsad", 2);

    garage.insert(*vhcl);

    REQUIRE(areCarsEqual(garage[0], *vhcl));
    delete vhcl;
}

TEST_CASE("Test Garage.insert() multiple vehicles"){
    Garage garage = Garage(2);
    Vehicle* vhcl = new Vehicle("asdsad", "asdsad", 2);
    Vehicle* car = new Vehicle("car", "asdsad", 2);

    garage.insert(*vhcl);

    REQUIRE_THROWS(garage.insert(*car));

    delete car;
    delete vhcl;
}

TEST_CASE("Assignment operator with normal values"){
    Garage garage1 = Garage(5);
    Garage garage2 = Garage(2);

    Vehicle* car1 = new Vehicle("Fast", "brown", 2);
    Vehicle* car2 = new Vehicle("Quick", "White", 1);

    garage1.insert(*car1);
    garage1.insert(*car2);

    garage2 = garage1;

    REQUIRE(garage1.size() == garage2.size());
    for (int i = 0; i < 2; ++i) {
        REQUIRE(areCarsEqual(garage2[i], garage1[i]));
    }

    delete car1;
    delete car2;
}

TEST_CASE("Assignment operator with corrupted values"){
    Garage garage1 = Garage(5);

    Vehicle* car1 = new Vehicle("", "", 2);
    Vehicle* car2 = new Vehicle("Quick\\", "White", 1);

    garage1.insert(*car1);
    garage1.insert(*car2);

    REQUIRE(garage1.find(""));
    REQUIRE(garage1.find("Quick\\"));

    delete car1;
    delete car2;
}

TEST_CASE("Erase function") {
    Garage garage = Garage(10);
    Vehicle* vhcl = new Vehicle("asdsad", "asdsad", 2);
    Vehicle* car = new Vehicle("car", "asdsad", 2);

    garage.insert(*vhcl);
    garage.insert(*car);

    garage.erase(vhcl->registration());

    REQUIRE(garage.find(car->registration()) != nullptr);
    REQUIRE(garage.find(vhcl->registration()) == nullptr);

    delete car;
    delete vhcl;
}

TEST_CASE("Erase not existing car") {
    Garage garage = Garage(10);
    Vehicle* car = new Vehicle("car", "asdsad", 2);

    garage.erase(car->registration());

    REQUIRE(garage.find(car->registration()) == nullptr);

    delete car;
}