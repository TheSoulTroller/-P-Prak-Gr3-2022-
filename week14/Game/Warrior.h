#pragma once
#include "Hero.h"

class Warrior: public Hero
{
private:
    int rage;

public:

    Warrior(const String& name, int hp = 120, int rage = 0) : Hero(name, hp), rage(rage)
    {};
    ~Warrior() = default;

    int getRage() const{
        return rage;
    }

    void attack(Hero*& enemy) override
    {
        cout << this->name << " attacks " << enemy->getName() << " with rage and deals " << (rage + 10) << " damage!" << endl;
        enemy->setHp(enemy->getHp() - (rage + 10));
        rage += 20;
    }

    virtual void print() const override
    {
        cout << "I am " << this->name << " the Warrior, I have " << this->hp << " hp and " << this->rage << " rage!" << endl;
    }
};