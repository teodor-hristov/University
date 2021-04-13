cmake_minimum_required(VERSION 3.17)
project(Hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hw1 main.cpp MyString/MyString.cpp Vehicle/Vehicle.cpp Garage/Garage.cpp)
add_executable(StringTest MyString/MyStringTests.cpp catch_amalgamated.cpp MyString/MyString.cpp)

add_executable(VehicleTest Vehicle/VehicleTests.cpp Vehicle/Vehicle.cpp MyString/MyString.cpp catch_amalgamated.cpp)
add_executable(GarageTest Garage/GarageTests.cpp Garage/Garage.cpp Vehicle/Vehicle.cpp MyString/MyString.cpp catch_amalgamated.cpp)
