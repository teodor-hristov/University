#include <iostream>
#include "MyString/MyString.hpp"
#include "Garage/Garage.hpp"
#include "Vehicle/Vehicle.hpp"

using namespace std;

void printGarage(Garage &garage) {
    const char* desc;
    const char* reg;

    for (int i = 0; i < garage.getLastIndex(); ++i) {
        reg = garage[i].registration();
        desc = garage[i].description();

        cout << "Id: " << i <<"\nDesc: " << desc << "\nRegistration: " << reg << "\nSize: "
             << garage[i].space() << endl;

        delete reg;
        delete desc;
    }
}

void printMenu() {
    cout << "Choose an option:\n1.Add car to garage.\n2.Remove car from garage.\n3.Print garage.\n4.Esc\n";
}

void addCar(Garage &garage) {
    int spots;
    char registration[128], description[128];
    Vehicle *vhcl;

    cout << "Enter registration:" << endl;
    cin.ignore();
    cin.getline(registration, 128);

    cout << "Enter description:" << endl;
    cin.ignore();
    cin.getline(description, 128);

    cout << "Enter car size:" << endl;
    cin >> spots;

    vhcl = new Vehicle(registration, description, spots);

    garage.insert(*vhcl);
}

void removeCar(Garage &garage) {
    int index;
    const char* reg;
    cout << "Choose car: " << endl;

    printGarage(garage);

    cin >> index;
    reg = garage[index].registration();
    garage.erase(reg);

    delete reg;
}


int main() {
    size_t garageSize;
    cout << "Garage size: " << endl;
    cin >> garageSize;
    Garage garage = Garage(garageSize);

    int option;
    while (1) {
        printMenu();
        cin >> option;
        switch (option) {
            case 1:
                addCar(garage);
                break;
            case 2:
                removeCar(garage);
                break;
            case 3:
                printGarage(garage);
                cout << endl;
                break;
            default:

                return 0;
        }
    }

}
