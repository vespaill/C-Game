#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "Creature.hpp"


class Player: public Creature {

private:
    unsigned levelingPoints;
    unsigned curXp;
    unsigned xpNeededToLvl;

public:
    Player(const Creature& nc=Creature("new-player",0,0,1,1,1)):Creature(nc){};
    bool earnedNewLvl();
    bool shouldLevelUp();
    void levelUp();
    void slightAllTraitsIncrement(const unsigned& amount=5);
    bool chooseStatToLevel();


};

#endif // _PLAYER_HPP
