#ifndef _CREATURE_HPP
#define _CREATURE_HPP

#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

const unsigned MAX_HP = 20484;

class Creature {

protected:
    string name;
    int x;                  // location x
    int y;                  // location y

    // Stats
    unsigned vigor;          // Affects HP
    unsigned strength;       // Affects AP
    unsigned intelligence;   // Affects MP

    // Traits
    unsigned HP;             // Health points
    unsigned curHP;
    unsigned AP;             // Attack power
    unsigned MP;             // Magic power

public:
    Creature(const string& ni="new-creature", const int& xi=0, const int& yi=0,
             const unsigned& vi=1, const unsigned& si=1, const unsigned& ii=1);
    bool isDead();
    void updateTraits();

    void heal(const unsigned& amount=MAX_HP);
    void damage(const unsigned &amount);
    void displayStats();

};

#endif // _CREATURE_HPP
