#include "../Employee/Employee.h"

class Company{
private:
    Employee employees[1000];
    int employeeCount;
public:
    Company();
    const Employee* getEmployees();
    bool addEmployee(Employee &empl);
    bool dismissEmployee(Employee const &empl);
    bool isThereEmployees();
    void sortEmployeesByName();
    void printSalary();
    void printSalary(char* department);
    void increaseSalary(Employee &empl, double percentage);
    void printEmployees(char* department);

    int getEmployeeCount() const;

    void setEmployeeCount(int employeeCount);
};