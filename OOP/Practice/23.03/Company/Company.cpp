#include <iostream>
#include "Company.h"

bool eqString(const char* str1, const char* str2) {
    for (int i = 0; i < 50; ++i) {
        if(str1[i] == '\0' || str2[i] == '\0'){
            break;
        }
        if(str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

bool equal(Employee const &empl1, Employee const &empl2) {
    if(empl1.getSalary() == empl2.getSalary() && eqString(empl1.getName(), empl2.getName()) && eqString(empl1.getDepartmentName(), empl2.getDepartmentName())){
        return true;
    } else {
        return false;
    }
}

int findEmpl(Employee &empl, const Employee* employees, int len){
    for (int i = 0; i < len; ++i) {
        if(equal(empl, employees[i])){
            return i;
        }
    }

    return -1;
}

Company::Company() {
    this->employeeCount = 0;
}

const Employee* Company::getEmployees() {
    return this->employees;
}

bool Company::addEmployee(Employee &empl) {
    if(this->getEmployeeCount() >= 1000) {
        std::cout << empl.getName() << " is not added." << std::endl;
        return false;
    }else {
        this->employees[this->getEmployeeCount()] = empl;
        this->setEmployeeCount(this->getEmployeeCount() + 1);
        std::cout << empl.getName() << " added." << std::endl;
        return true;
    }
}

bool Company::dismissEmployee(Employee const &empl) {
    int index = -1;
    for (int i = 0; i < this->getEmployeeCount(); ++i) {
        if(equal(this->getEmployees()[i], empl)) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        std::cout << empl.getName() << " not found." << std::endl;
        return false;
    }

    for (int i = index + 1; i < this->getEmployeeCount(); ++i) {
        this->employees[i - 1] = this->employees[i];
    }

    this->setEmployeeCount(this->getEmployeeCount() - 1);
    std::cout << empl.getName() << " dismissed." << std::endl;

    return true;
}

bool Company::isThereEmployees() {
    return this->getEmployeeCount();
}

void Company::sortEmployeesByName() {

}

void Company::printSalary() {
    unsigned int salary = 0;
    for (int i = 0; i < this->getEmployeeCount(); ++i) {
        salary += this->getEmployees()[i].getSalary();
    }

    std::cout << "Salary for all employees: " << salary << std::endl;
}

void Company::printSalary(char *department) {
    unsigned int salary = 0;
    for (int i = 0; i < this->getEmployeeCount(); ++i) {
        if(eqString(department, this->getEmployees()[i].getDepartmentName())){
            salary += this->getEmployees()[i].getSalary();
        }
    }

    std::cout << "Salary for department " << department << " : " << salary << std::endl;
}

void Company::increaseSalary(Employee &empl, double percentage) {
    int emplIndex = findEmpl(empl, this->getEmployees(), this->getEmployeeCount());
    if(emplIndex >= 0){
        this->employees[emplIndex].setSalary(empl.getSalary() + empl.getSalary()*percentage/100);
    }
    empl.setSalary(empl.getSalary() + empl.getSalary()*percentage/100);
}

void Company::printEmployees(char* department) {
    for (int i = 0; i < this->getEmployeeCount(); ++i) {
        Employee temp = this->employees[i];

        if(eqString(department, temp.getDepartmentName())) {
            temp.printData();
        }

    }
}

int Company::getEmployeeCount() const {
    return this->employeeCount;
}

void Company::setEmployeeCount(int employeeCount) {
    Company::employeeCount = employeeCount;
}

