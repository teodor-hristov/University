#include <iostream>
#include "Warrior.cpp"
#include "Weapon.cpp"

using namespace std;

void fight(Warrior &warrior1, Warrior &warrior2){
    cout << "Fight between " << warrior1.getName() << " and "
    << warrior2.getName() << " has been started." << endl;
    while(1){
        if(warrior1.getHealth() && warrior1.getWeapon().getDurability()) {
            warrior1.attack(warrior2);
        }else {
            cout << "===============\n" << warrior1.getName() << " is dead.\n" << "===============" << endl;
            break;
        }
        if(warrior2.getHealth() && warrior2.getWeapon().getDurability()){
            warrior2.attack(warrior1);
        } else {
            cout << "===============\n" << warrior2.getName() << " is dead.\n" << "===============" << endl;
            break;
        }
    }
}

int main() {
    Weapon motika = Weapon("Moti4ka", 3, 3);
    Weapon lopata = Weapon("Golqma prava lopata", 4, 80);
    Warrior pesho = Warrior("Pesho", 7, 400, lopata);
    Warrior gosho = Warrior("Goshootpochivka", 6, 450, motika);

    fight(pesho,gosho);
}