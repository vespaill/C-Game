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
    fillHealth();

    // cout << name << " is alive!" << endl;

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

void Creature::heal(const unsigned& amount) {

    unsigned total = curHP + amount;
    curHP = (total > HP)? HP : total;

}

void Creature::damage(const unsigned &amount) {

    curHP = (amount > curHP)? 0 : curHP-amount;

}

void Creature::displayStats() {
    cout << "        name : " << name << endl
         << " coordinates : (" << x << ", " << y << ')' << endl
         << "          HP : " << curHP << '/' << HP << endl
         << "          AP : " << AP << endl
         << "          MP : " << MP << endl
         << "       vigor : " << vigor << endl
         << "    strength : " << strength << endl
         << "intelligence : " << intelligence << endl;
}
