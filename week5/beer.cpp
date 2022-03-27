#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include "beer.h"

using std::cin;
using std::cout;
using std::endl;

void Beer::erase()
{
    delete[] this->name;
}
void Beer::copy(const Beer& other)
{
    this->name = new char [strlen(other.getName()) + 1];
    strcpy(this->name, other.getName());
    this->mil = other.getMil();
}


void Beer::setMil(int mil)
{
    this->mil = mil;
}
void Beer::setName(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const char* Beer::getName() const
{
    return this->name;
}
int Beer::getMil()const
{
    return this->mil;
}

Beer::Beer()
{
    setName("");
    setMil(0);
}
Beer::Beer(const char* name, int mil)
{
    setName(name);
    setMil(mil);
}
Beer::Beer(const Beer& other)
{
    setName(other.getName());
    setMil(other.getMil());
}
Beer::~Beer()
{
    erase();
}

void Beer::addBeer(Beer& other, int mil)
{
    if(mil > other.getMil()) 
    {
        cout << "\nYou can't add more milliteres than you have!" << endl;
        return;
    }
    other.setMil(other.getMil() - mil);
    setMil(getMil() + mil);

    char* newName = new char[strlen(getName()) + strlen(other.getName()) + 2];

    strcpy(newName, getName());
    strcat(newName, "&");
    strcat(newName, other.getName());

    setName(newName);
    delete[] newName;
}
bool Beer::check(const char* name)const
{
    char* check;
    check = strstr(this->name,name);
    if(check != NULL) return true;
    return false;
}
void Beer::print() const
{
    cout << "\nName: " << getName() << endl;
    cout << "Milliteres: " << getMil() << endl << "___________________" << endl;
}

int main()
{
    Beer beer("Stella Artois", 500);
    Beer beer1("Becks", 500);
    Beer beer2("Heineken", 500);

    cout << "All beers: " << endl;
    beer.print();
    beer1.print();
    beer2.print();

    beer1.addBeer(beer2, 250);

    cout << "Beer1: " << endl;
    beer1.print();
    cout << "Beer2: " << endl;
    beer2.print();

    cout << "Checking for Heineken: " << std::boolalpha << beer1.check("Heineken") << endl;
    cout << "Checking for Stella Artois: " << std::boolalpha << beer1.check("Stella Artois") << endl;
    cout << "Checking for " << beer2.getName() << ": " << std::boolalpha << beer1.check(beer2.getName()) << endl;

    return 0;
}