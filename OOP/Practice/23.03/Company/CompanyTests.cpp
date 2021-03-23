#include "../catch_amalgamated.hpp"
#include "Company.h"

Company tmp = Company();
Employee emp1 = Employee("Hristo", "R&D", 50, 999);
Employee emp2 = Employee("Gosho", "R&D", 60, 500);
Employee emp3 = Employee("Asen", "QA", 20, 800);
Employee emp4 = Employee("Petar", "QA", 25, 678);

TEST_CASE("Equal names"){
    for (int i = 0; i < 1000; ++i) {
        REQUIRE(strcmp(tmp.getEmployees()[i].getName(), "") == 0);
    }
}

TEST_CASE("Dismiss dismissed person"){
    REQUIRE(tmp.dismissEmployee(emp4) == 0);
}

