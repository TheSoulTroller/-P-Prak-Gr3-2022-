#pragma once
#include "Hero.h"

class Magician: public Hero
{
private:
    int mana;

public:

    Magician(const String& name, int hp = 100, int mana = 200) : Hero(name, hp), mana(mana)
    {};
    ~Magician() = default;

    int getMana() const{
        return mana;
    }

    void attack(Hero*& enemy) override
    {
        if (mana > 0)
        {
            cout << this->name << " attacks " << enemy->getName() << " with rage and deals " << mana << " damage!" << endl;
            enemy->setHp(enemy->getHp() - mana);
            mana -= 20;
        }
        else
        {
            cout << this-> name << " is out of mana!" << endl;  
        }
    }

    virtual void print() const override
    {
        cout << "I am " << this->name << " the Magician, I have " << this->hp << " hp and " << this->mana << " mana!" << endl;
    }
};