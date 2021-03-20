//
// Created by tedo3637 on 16.03.21 г..
//

#include "Weapon.h"
Weapon::Weapon() {
    this->setStrength(0);
    this->setName("");
    this->durability = 0;
}
Weapon::Weapon(char* name, int strength, int durability) {
    this->setName(name);
    this->setStrength(strength);
    this->setDurability(durability);
}

char * Weapon::getName() {
    return this->getName();
}

void Weapon::setName(char *name) {
    for (int i = 0; i < 20; ++i) {
        this->name[i] = name[i];
    }
}

int Weapon::getDurability() {return this->durability;}
void Weapon::setDurability(int value) {
    if(value >= 0){
        this->durability = value;
    } else {
        this->durability = 0;
    }
}
int Weapon::getStrength() {return this->strength;}
void Weapon::setStrength(int value) {
    if(value >= 0){
        this->strength = value;
    }
}
