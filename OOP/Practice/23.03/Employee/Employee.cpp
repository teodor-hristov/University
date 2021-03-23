#include <iostream>
#include "Employee.h"

Employee::Employee(){
    this->setName("");
    this->salary = 0;
    this->age = 0;
    this->setDepartmentName("");
}

Employee::Employee(char *name, char *departmentName, short age, int salary) {
    setName(name);
    setAge(age);
    setDepartmentName(departmentName);
    setSalary(salary);
}

const char *Employee::getName() const {
    return this->name;
}

const char *Employee::getDepartmentName() const {
    return this->departmentName;
}

short Employee::getAge() const {
    return this->age;
}

int Employee::getSalary() const {
    return this->salary;
}

bool Employee::setName(char* name) {
    int lastIndex = 0;
    for (int i = 0; i < 49; ++i) {
        if(name[i] != '\0'){
            this->name[i] = name[i];
        }else {
            lastIndex = i;
            break;
        }
    }
    this->name[lastIndex] = '\0';
    return true;
}

bool Employee::setDepartmentName(char* name) {
    int lastIndex = 0;
    for (int i = 0; i < 49; ++i) {
        if(name[i] != '\0'){
            this->departmentName[i] = name[i];
        }else {
            lastIndex = i;
            break;
        }
    }
    this->departmentName[lastIndex] = '\0';
    return true;
}

void Employee::setAge(short age) {
    if(age >= 18 && age <= 64){
        this->age = age;
    } else {
        std::cout << "Too young." << std::endl;
    }
}

void Employee::setSalary(int salary) {
    if(salary < 610 || salary > 1000){
        salary = 610; //set minimal
        std::cout << "Wrong input." << std::endl;
    }else {
        this->salary = salary;
    }
}
void Employee::printData(){
    std::cout << "Name: " << this->getName()
    << "\nDepartment: " << this->getDepartmentName()
    <<  "\nAge: " << this->getAge()
    << "\nSalary: " << this->getSalary() << std::endl;
}


