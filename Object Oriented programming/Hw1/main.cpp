#include <iostream>
#include "MyString/MyString.hpp"
#include "Garage/Garage.hpp"
#include "Vehicle/Vehicle.hpp"
#include "VehicleAllocator/VehicleAllocator.hpp"

using namespace std;

void printGarage(Garage &garage) {

    for (int i = 0; i < garage.getLastIndex(); ++i) {
        cout << "Id: " << i <<"\nDesc: " << garage[i].description() << "\nRegistration: " << garage[i].registration() << "\nSize: "
             << garage[i].space() << endl;
    }
}

void printMenu() {
    cout << "Choose an option:\n1.Add car to garage.\n2.Remove car from garage.\n3.Print garage.\n4.Esc\n";
}

void addCar(VehicleAllocator &vhclAlloc, Garage &garage) {
    Vehicle* vhcl = vhclAlloc.createVehicle(garage);
    garage.insert(*vhcl);
}

void removeCar(Garage &garage) {
    int index;
    cout << "Choose car: " << endl;

    printGarage(garage);

    cin >> index;
    garage.erase(garage[index].registration());
}


int main() {
    size_t garageSize;
    cout << "Garage size: " << endl;
    cin >> garageSize;
    Garage garage = Garage(garageSize);
    VehicleAllocator vhcls = VehicleAllocator();

    int option;
    while (1) {
        printMenu();
        cin >> option;
        switch (option) {
            case 1:
                addCar(vhcls,garage);
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
