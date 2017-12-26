#include "Player.hpp"

void printNewlines(const unsigned& amount=50);

int main() {

    Player p1(Creature("vicander"));

    for (int i = 0; i < 10000; i++) {
        printNewlines();
        p1.displayCreatureInformation();
        std::cout << std::endl;
        p1.levelUp();
        p1.promptLevelUpOptions();
    }

}

void printNewlines(const unsigned& amount) {

    for (int i = amount; i > 0; i--)
        std::cout << std::endl;

}
