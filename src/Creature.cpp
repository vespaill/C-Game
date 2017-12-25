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

    HP = vigor*10;
    AP = strength*10;
    MP = intelligence*10;

}

void Creature::fillHealth() {

    curHP = HP;

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
