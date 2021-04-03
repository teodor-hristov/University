#pragma once

#include "Vehicle.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("Test ctor"){
    Vehicle seat = Vehicle("Lorem Ipsum is simply dummy", "text of the printing", 2);

    REQUIRE(strcmp(seat.registration(), "Lorem Ipsum is simply dummy") == 0);
    REQUIRE(strcmp(seat.description(), "text of the printing") == 0);
}

TEST_CASE("Vehicle.registration() with empty char*"){
    Vehicle seat = Vehicle("", "", 2);

    REQUIRE(strcmp(seat.registration(), "") == 0);
    REQUIRE(strcmp(seat.description(), "") == 0);
}
