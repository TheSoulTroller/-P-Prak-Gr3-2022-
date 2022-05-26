#include "Arena.h"
#include "Hero.h"
#include "Warrior.h"
#include "Magician.h"

int main()
{
    Hero* hero5 = new Magician("Radagast", 5000, 1000);
    Hero* hero1 = new Magician("Gandalf",3000, 1000);
    Hero* hero2 = new Warrior("Hulk Hogan", 800, 100);
    Hero* hero3 = new Warrior("Bruce Lee", 900, 100);
    Hero* hero4 = new Warrior("Jackie Chan", 1000, 100);
    

    Hero** heroes = new Hero*[5];
    heroes[0] = hero5;
    heroes[1] = hero1;
    heroes[2] = hero2;
    heroes[3] = hero3;
    heroes[4] = hero4;
    
    Hero** duel = new Hero*[2];
    duel[0] = hero5;
    duel[1] = hero2;

    // Arena arena(5,heroes);
    Arena arena(2, duel);
    arena.game();
}