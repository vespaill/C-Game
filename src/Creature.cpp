#include "Creature.hpp"

Creature::Creature(const std::string& ni, const int& xi, const int& yi,
                   const unsigned& vi, const unsigned& si, const unsigned& ii) {

    name = ni;
    x = xi;
    y = yi;
    vigor = vi;
    strength = si;
    intelligence = ii;
    // HPbonus = APbonus = MPbonus = 0;
    HPbonus = 0;
    APbonus = 0;
    MPbonus = 0;
    updateTraits();
    heal();

}

Creature::Creature(const Creature& nc) {

    *this = nc;
    updateTraits();

}

Creature& Creature::operator=(const Creature& nc) {

    name = nc.name;
    x = nc.x;
    y = nc.y;
    vigor = nc.vigor;
    strength = nc.strength;
    intelligence = nc.intelligence;
    HPbonus = nc.HPbonus;
    APbonus = nc.APbonus;
    MPbonus = nc.MPbonus;
    return *this;

}

bool Creature::isDead() {

    return curHP > 0? false : true;

}


void Creature::increaseOtherTraitsBonus(const char& trait, const unsigned& amount) {

    switch (trait) {
        case 'v':
            APbonus += amount;
            MPbonus += amount;
            break;
        case 's':
            HPbonus += amount;
            MPbonus += amount;
            break;
        case 'i':
            HPbonus += amount;
            APbonus += amount;
            break;
    }

}

void Creature::updateTraits() {

    HP = 90 + vigor*(2*(vigor-1)+10) + HPbonus;
    AP = 45 + strength*(strength+4) + APbonus;
    MP = 45 + intelligence*(intelligence+4) + MPbonus;
    LVL = vigor+strength+intelligence;

    heal();

}

void Creature::increaseStat(const char& stat, const unsigned& amount) {

    switch (stat) {
        case 'v':
            vigor += amount;
            break;
        case 's':
            strength += amount;
            break;
        case 'i':
            intelligence += amount;
            break;
    }

}

void Creature::heal(const unsigned& amount) {

    unsigned total = curHP + amount;
    curHP = (total > HP)? HP : total;

}

void Creature::damage(const unsigned &amount) {

    curHP = (amount > curHP)? 0 : curHP-amount;

}

void Creature::displayCreatureInformation() {

    std::cout << "       name : " << name << std::endl;
    // displayLocation();
    displayStatsAndTraits();
    // displayStats();
    // displayTraits();

}

void Creature::displayLocation() {

    std::cout << " coordinates : (" << x << ", " << y << ')' << std::endl;

}

void Creature::displayStatsAndTraits() {

    std::cout << "\tLVL : " << LVL << std::endl
              << "HP : " << curHP << '/' << HP << "  \t       vigor : " << vigor << std::endl
              << "AP : " << AP << "\t\t    strength : " << strength << std::endl
              << "MP : " << MP << "\t\tintelligence : " << intelligence  << std::endl;

}

void Creature::displayStats() {

    std::cout << "       vigor : " << vigor << std::endl
              << "    strength : " << strength << std::endl
              << "intelligence : " << intelligence << std::endl;

}

void Creature::displayTraits() {

    std::cout << "          HP : " << curHP << '/' << HP << std::endl
              << "          AP : " << AP << std::endl
              << "          MP : " << MP << std::endl
              << "         LVL : " << LVL << std::endl;

}
