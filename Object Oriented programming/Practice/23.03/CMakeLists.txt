cmake_minimum_required(VERSION 3.17)
project(23_03)

set(CMAKE_CXX_STANDARD 14)

add_executable(Run main.cpp Employee/Employee.cpp Company/Company.cpp)

add_executable(TestEmployee catch_amalgamated.cpp Employee/EmployeeTests.cpp Employee/Employee.cpp)
add_executable(TestCompany catch_amalgamated.cpp Employee/Employee.cpp Company/Company.cpp Company/CompanyTests.cpp)

add_executable(23_03 main.cpp)