#include "Player.hpp"

bool Player::earnedNewLvl() {

    return curXp >= xpNeededToLvl;

}

bool Player::shouldLevelUp() {

    return earnedNewLvl() && LVL < LVL_CAP;

}

void Player::levelUp() {

        levelingPoints++;
        curXp = curXp - xpNeededToLvl;
        xpNeededToLvl = pow(xpNeededToLvl, 2);

        slightAllTraitsIncrement();
        chooseStatToLevel();

}

void Player::slightAllTraitsIncrement(const unsigned& amount) {

    HP += amount;
    AP += amount;
    MP += amount;

}


