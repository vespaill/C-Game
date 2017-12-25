#include "Creature.hpp"

Creature::Creature(const string& ni, const int& xi, const int& yi,
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

    cout << "        name : " << name << endl;
    displayLocation();
    displayStats();
    displayTraits();

}

void Creature::displayLocation() {

    cout << " coordinates : (" << x << ", " << y << ')' << endl;

}

void Creature::displayStats() {

    cout << "       vigor : " << vigor << endl
         << "    strength : " << strength << endl
         << "intelligence : " << intelligence << endl;

}

void Creature::displayTraits() {

    cout << "          HP : " << curHP << '/' << HP << endl
         << "          AP : " << AP << endl
         << "          MP : " << MP << endl
         << "         LVL : " << LVL << endl;

}
