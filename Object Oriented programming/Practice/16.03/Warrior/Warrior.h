//
// Created by tedo3637 on 16.03.21 г..
//
#include "Weapon.h"
#ifndef TEST_WARRIOR_H
#define TEST_WARRIOR_H


class Warrior {
private:
    char name[20];
    int strength;
    int health;
    Weapon weapon;
public:
    Warrior();
    Warrior(char* name, int strength, int health, Weapon &weapon);
    void setName(char* name);
    void setStrength(int value);
    void setHealth(int value);
    void setWeapon(Weapon &value);
    char* getName();
    int getStrength();
    int getHealth();
    Weapon getWeapon();
    ~Warrior();

    void attack(Warrior &victim);

};


#endif //TEST_WARRIOR_H
