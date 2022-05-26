#pragma once
#include <iostream>
#include "String.h"

class Hero
{
protected:
    String name;
    int hp;

public:
    Hero()
    {
        name = "";
        hp = 0;
    }

    Hero(const String& name, int hp = 100) : name(name), hp(hp){

    };
    Hero& operator=(const Hero& other)
    {
        if (this != &other)
        {
            this->name = other.name;
            this->hp = other.hp;
        }
        return *this;
    }
    virtual ~Hero(){
    };

    void setHp(int hp)
    {
        this->hp = hp;
    }
    int getHp() const{
        return hp;
    }
    String getName() const{
        return name;
    }

    virtual void print() const = 0;
    virtual void attack(Hero*& enemy) = 0;
};