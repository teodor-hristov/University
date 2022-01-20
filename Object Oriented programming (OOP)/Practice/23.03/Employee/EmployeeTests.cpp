#include "../catch_amalgamated.hpp"
#include "Employee.h"

TEST_CASE(){
    Employee empl = Employee("Peshoasdasdasd", "R&D", 19, 640);
    REQUIRE(empl.getAge() < 64);
    REQUIRE(empl.getAge() > 18);
    REQUIRE(empl.getSalary() >= 640);
    REQUIRE(empl.getSalary() <= 1000);
}
