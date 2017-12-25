#include "Player.hpp"

int main() {

    Player p1(Creature("vicander"));

    for (int i = 0; i < 5; i++) {
        p1.displayStats();
        p1.displayTraits();
        p1.increaseStat('v');
        p1.increaseStat('s');
        p1.increaseStat('i');
        cout << endl;
    }

}