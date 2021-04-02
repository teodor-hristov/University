cmake_minimum_required(VERSION 3.17)
project(Hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hw1 main.cpp MyString/MyString.cpp)
add_executable(StringTest MyString/MyStringTests.cpp catch_amalgamated.cpp MyString/MyString.cpp)