#ifndef _CREATURE_HPP
#define _CREATURE_HPP

#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

const unsigned MAX_HP = 20484;
#define LVL_CAP 99

class Creature {

protected:
    string name;
    int x;                  // location x
    int y;                  // location y

    // Stats
    unsigned vigor;          // Affects HP
    unsigned strength;       // Affects AP
    unsigned intelligence;   // Affects MP

    // Traits: Determined by the stats above.
    unsigned HP;             // Health points
    unsigned AP;             // Attack power
    unsigned MP;             // Magic power
    unsigned LVL;

    unsigned curHP;

public:
    Creature(const string& ni="new-creature", const int& xi=0, const int& yi=0,
             const unsigned& vi=1, const unsigned& si=1, const unsigned& ii=1);
    Creature(const Creature& nc);

    void increaseStat(const char& stat, const unsigned& amount=1);
    void updateTraits();

    void heal(const unsigned& amount=MAX_HP);
    void damage(const unsigned &amount);
    bool isDead();

    void displayCreatureInformation();
    void displayLocation();
    void displayTraits();
    void displayStats();

    Creature& operator=(const Creature& nc);

};

#endif // _CREATURE_HPP
