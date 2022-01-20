#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "Warrior.h"
#include "Weapon.h"

Warrior::Warrior() {
    this->setName("NAN");
    this->setStrength(0);
    this->setHealth(0);
}

Warrior::Warrior(char *name, int strength, int health, Weapon &weapon) {
    this->setName(name);
    this->setStrength(strength);
    this->setWeapon(weapon);
    this->setHealth(health);
}

Warrior::~Warrior() {

}

int Warrior::getStrength() {
    return this->strength;
}

void Warrior::setStrength(int value) {
    this->strength = value;
}

void Warrior::setName(char *name) {
    for (int i = 0; i < 20; ++i) {
        this->name[i] = name[i];
    }
}

char *Warrior::getName() {
    return this->name;
}

int Warrior::getHealth() {
    return this->health;
}

void Warrior::setHealth(int value) {
    if (value >= 0) {
        this->health = value;
    } else {
        this->health = 0;
    }
}

Weapon Warrior::getWeapon() {
    return this->weapon;
}

void Warrior::setWeapon(Weapon &value) {
    this->weapon = value;
}

void Warrior::attack(Warrior &victim) {
    Weapon temp = this->getWeapon();

    std::cout <<"       " <<victim.getName() << " took " << this->getWeapon().getStrength() + this->getStrength()
              << " damage from " << this->getName()
              << "\n        current health: " << this->getName() << " : " << victim.getName() << " " << this->getHealth()
              << " -> " << victim.getHealth() << "\n";
    victim.setHealth(victim.getHealth() - this->getStrength() + this->getWeapon().getStrength());
    temp.setDurability(this->getWeapon().getDurability() - 1);
    this->setWeapon(temp);
}
