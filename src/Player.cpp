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

}

void Player::promptLevelUpOptions() {

    char a;

    std::cout << "Level up! Choose a stat to improve\n"
                 "       Vigor - \'v\'\n"
                 "    Strength - \'s\'\n"
                 "intelligence - \'i\'\n: ";
    while (true) {
        std::cin >> a;
        if (a == 'v' || a == 's' || a == 'i')
            break;
        std::cout << "Only options are v, s or i: ";
    }
    increaseOtherTraitsBonus(a);
    increaseStat(a);
    updateTraits();

}
