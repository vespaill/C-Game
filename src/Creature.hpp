#ifndef _CREATURE_HPP
#define _CREATURE_HPP

#include "Clibrary.hpp"
#define LVL_CAP 99
const unsigned MAX_HP = 20484;

class Creature {

protected:
    std::string name;
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

    unsigned HPbonus;
    unsigned APbonus;
    unsigned MPbonus;

    unsigned curHP;

public:
    Creature(const std::string& ni="new-creature", const int& xi=0, const int& yi=0,
             const unsigned& vi=1, const unsigned& si=1, const unsigned& ii=1);
    Creature(const Creature& nc);


    void increaseStat(const char& stat, const unsigned& amount=1);
    void increaseOtherTraitsBonus(const char& trait, const unsigned& amount=3);
    void updateTraits();


    void heal(const unsigned& amount=MAX_HP);
    void damage(const unsigned &amount);
    bool isDead();

    void displayCreatureInformation();
    void displayLocation();
    void displayStatsAndTraits();
    void displayTraits();
    void displayStats();

    Creature& operator=(const Creature& nc);

};

#endif // _CREATURE_HPP
