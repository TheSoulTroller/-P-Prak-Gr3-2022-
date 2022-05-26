#pragma once
#include "Hero.h"

class Arena
{
private:
    Hero** heroes;
    int numOfHeroes;

    void removeDeadHeroes()
    {
        for (int i = 0; i < numOfHeroes; i++)
        {
            if (heroes[i] == nullptr)
            {
                for (int j = i; j < numOfHeroes - 1; j++)
                {
                    heroes[j] = heroes[j + 1];
                }
                numOfHeroes--;
                --i;
            }
        }
    }

public:
    Arena(int _numOfHeroes, Hero**& _heroes)
    {
        this->numOfHeroes = _numOfHeroes;
        this->heroes = new Hero*[numOfHeroes];
        for (int i = 0; i < numOfHeroes; i++)
        {
            this->heroes[i] = _heroes[i];
        }
    }    

    ~Arena()
    {
        for (int i = 0; i < numOfHeroes; i++)
        {
            delete heroes[i];
        }
        delete[] heroes;
    }

    void print() const
    {
        for (int i = 0; i < numOfHeroes; i++)
        {
            if(heroes[i] != nullptr)
            {
                heroes[i]->print();
            }
        }
    }

    void round()
    {
        system("clear");
        this->print();
        cout << "_____________________________________\n";
        cout << "Round started" << endl;
        int index;
        for (int i = 0; i < numOfHeroes; i++)
        {
            if (heroes[i] != nullptr && heroes[i]->getHp() > 0)
            {
                cout << heroes[i]->getName() << " is attacking choose your enemy index" << endl;
                cout << "Enemies: " << endl;
                for (int j = 0; j < numOfHeroes; j++)
                {
                    if (i != j && heroes[j] != nullptr)
                        cout << '\t' << heroes[j]->getName() << " with index " << j << endl;
                }

                cout << "\nEnter index of enemy: ";
                cin >> index;
                while (index < 0 || index >= numOfHeroes || index == i)
                {
                    cout << "Invalid index. Try again: ";
                    cin >> index;
                }

                if (heroes[index] != nullptr)
                {
                    heroes[i]->attack(heroes[index]);
                }
                if (heroes[index]->getHp() <= 0)
                {
                    delete heroes[index];
                    heroes[index] = nullptr;
                }
            }
        }
        cout << "Round ended" << endl;
        cout << "_____________________________________\n";
        this->removeDeadHeroes();
    }

    void game()
    {
        while (numOfHeroes > 1)
        {
            round();
        }
        cout << "Winner winner chicken dinner for " << heroes[0]->getName() << endl;
    }
};