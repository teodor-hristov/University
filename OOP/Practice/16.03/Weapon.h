//
// Created by tedo3637 on 16.03.21 г..
//

#ifndef TEST_WEAPON_H
#define TEST_WEAPON_H


class Weapon {
private:
    char name[20];
    int strength;
    int durability;
public:
    Weapon();
    Weapon(char* name, int strength, int durability);
    void setName(char* name);
    void setStrength(int value);
    void setDurability(int value);
    char* getName();
    int getStrength();
    int getDurability();
};


#endif //TEST_WEAPON_H
