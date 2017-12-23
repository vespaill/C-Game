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

    cout << name << " is alive!" << endl;

}

void Creature::updateTraits() {

    HP = vigor*10;
    AP = strength*10;
    MP = intelligence*10;

}

void Creature::fillHealth() {

    curHP = HP;

}

bool Creature::isDead() {

    return curHP > 0? true:false;

}