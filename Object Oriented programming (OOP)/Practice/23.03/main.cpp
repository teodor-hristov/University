#include <iostream>
#include "Company/Company.h"

using namespace std;

int main(){
    Employee pesho = Employee("Pesho", "R&D", 19, 650);
    Employee ico = Employee("Hristo", "R&D", 19, 999);
    Employee gosho = Employee("ASD" , "QA",44, 999);
    Company visteon = Company();

    visteon.addEmployee(pesho);
    visteon.addEmployee(gosho);
    visteon.addEmployee(ico);

    //visteon.dismissEmployee(pesho);
    //visteon.dismissEmployee(gosho);

    visteon.increaseSalary(pesho, 10);
    visteon.printSalary("R&D");
    cout << (visteon.isThereEmployees()? "The company is not empty" : "The company is empty") << endl;
    visteon.printSalary();
    visteon.printEmployees("R&D");

    //pesho.printData();
}