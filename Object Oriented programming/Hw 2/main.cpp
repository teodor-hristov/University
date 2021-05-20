#include <iostream>
#include "Registration.h"
#include "Person.h"
#include "Vehicle.h"
#include "CommandInterpeter.h"

using namespace std;

int main() {
//    Registration reg("C1234AB");
//    Person az("Pesho");
//    Person toi("Sasho");
//    Vehicle smyrfa(reg, "Seat");
//    Vehicle corsa(reg, "Corsa");
//
//    smyrfa.setOwner(az);
//
//    az.addVehicle(smyrfa);
//    toi.addVehicle(corsa);
//
//    smyrfa.setOwner(toi);
//
//   az.printCars();
//   toi.printCars();
//
//   corsa.removeOwner();
//
//   toi.printCars();

    std::vector<Registration *> regs;
    std::vector<Person *> people;
    std::vector<Vehicle *> vhcls;

    CommandInterpreter ci(regs, vhcls, people);

    std::string c = "vehIcle C1234AV kuramiqnko";
    std::string c1 = "vehIcle C1234AB vtoroto";
    std::string qnko = "persoN \"Kura qnko\" 12";
    std::string qnko1 = "persoN \"Kura qnko1\" 13";
    std::string corsa = "aCQuire 12 C1234AB";
    std::string corsa1 = "aCQuire 12 C1234AV";
    std::string release = "reLease 13 C1234AB";
    std::string remove1 = "rEmOvE 12";
    std::string remove2 = "remove C1234AB";


    ci.interpret(c);
    ci.interpret(c1);

    ci.interpret(qnko);
    ci.interpret(qnko1);

    ci.interpret(corsa);

    ci.interpret(corsa1);

    ci.interpret(release);

    ci.interpret(remove1);
    ci.interpret(remove2);

    for (int i = 0; i < vhcls.size(); ++i) {
        std::cout << vhcls[i]->getRegistration().getRegistrationNumber() << "\n";
    }

    for (int i = 0; i < people.size(); ++i) {
        std::cout << *people[i] << "\n";
    }

    return 0;
}
