#include "Creature.hpp"

Creature::Creature(const std::string& ni, const int& xi, const int& yi,
                   const unsigned& vi, const unsigned& si, const unsigned& ii) {

    name = ni;
    x = xi;
    y = yi;
    vigor = vi;
    strength = si;
    intelligence = ii;
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
    return *this;

}

bool Creature::isDead() {

    return curHP > 0? false : true;

}

void Creature::updateTraits() {

    HP = 90 + vigor*(2*(vigor-1)+10);
    AP = 45 + strength*(strength+4);
    MP = 45 + intelligence*(intelligence+4);
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
    updateTraits();

}

void Creature::heal(const unsigned& amount) {

    unsigned total = curHP + amount;
    curHP = (total > HP)? HP : total;

}

void Creature::damage(const unsigned &amount) {

    curHP = (amount > curHP)? 0 : curHP-amount;

}

void Creature::displayCreatureInformation() {

    std::cout << "        name : " << name << std::endl;
    displayLocation();
    displayStats();
    displayTraits();

}

void Creature::displayLocation() {

    std::cout << " coordinates : (" << x << ", " << y << ')' << std::endl;

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
