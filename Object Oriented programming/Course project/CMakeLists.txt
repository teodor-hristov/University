cmake_minimum_required(VERSION 3.19)
project(Course_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Course_project main.cpp Image/Image.h Image/Image.cpp PbmImage/PbmImage.h PbmImage/PbmImage.cpp)