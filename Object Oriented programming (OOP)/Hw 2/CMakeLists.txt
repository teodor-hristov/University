cmake_minimum_required(VERSION 3.19)
project(Hw_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hw_2 main.cpp Registration.cpp Person.cpp Vehicle.cpp CommandInterpeter.h CommandInterpreter.cpp)
add_executable(RegistrationTest  RegistrationTest.cpp Registration.cpp Person.cpp Vehicle.cpp catch_amalgamated.cpp)
add_executable(PersonTest Registration.cpp Person.cpp Vehicle.cpp catch_amalgamated.cpp PersonTest.cpp)
add_executable(Interpreter Registration.cpp Person.cpp Vehicle.cpp CommandInterpreter.cpp catch_amalgamated.cpp InterpreterTests.cpp)