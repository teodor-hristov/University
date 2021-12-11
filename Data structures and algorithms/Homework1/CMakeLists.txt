cmake_minimum_required(VERSION 3.21)
project(Homework1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tests Source/tests.cpp Interfaces/interface.h Headers/Header.h Headers/MyStore.h Source/MyStore.cpp Headers/ClientWrapper.h Source/ClientWrapper.cpp Source/Utils.cpp Headers/Utils.h)
target_compile_definitions(Tests PUBLIC TESTING)

add_executable(ConsoleInput Source/ConsoleInput.cpp Interfaces/interface.h Headers/Header.h Headers/MyStore.h Source/MyStore.cpp Headers/ClientWrapper.h Source/ClientWrapper.cpp Headers/linked_list.hpp Source/Utils.cpp Headers/Utils.h Headers/Node.h)