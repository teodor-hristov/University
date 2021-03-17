//
// Created by tedo3637 on 16.03.21 г..
//

#include "Warrior.h"
#include "Weapon.h"

int Warrior::getStrength() {return this->strength;}
void Warrior::setStrength(int value) {this->strength = value;}
void Warrior::setName(char *name) {
    for (int i = 0; i < 20; ++i) {
        this->name[i] = name[i];
    }
}
char * Warrior::getName() {return this->name;}
int Warrior::getHealth() {return this->health;}
void Warrior::setHealth(int value) {
    if(value >=0){
        this->health = value;
    } else {
        this->health = 0;
    }
}
Weapon Warrior::getWeapon() {return this->weapon;}
void Warrior::setWeapon(Weapon &value) {this->weapon = value;}
Warrior::Warrior(char *name, int strength, int health, Weapon &weapon) {
    this->setName(name);
    this->setStrength(strength);
    this->setWeapon(weapon);
    this->setHealth(health);
}

void Warrior::attack(Warrior &victim) {
    int tempDurability = this->getWeapon().getDurability();
    std::cout << victim.getName() << " took " << this->getWeapon().getStrength() + this->getStrength() << " damage from " << this->getName()
    << "\n current health: " << this->getName() << " : " << victim.getName() << " " << this->getHealth() << " -> " << victim.getHealth() << "\n";
    victim.setHealth(victim.getHealth() - this->getStrength() + this->getWeapon().getStrength());
    this->getWeapon().setDurability( tempDurability - 1);
}

Warrior::~Warrior() {

}