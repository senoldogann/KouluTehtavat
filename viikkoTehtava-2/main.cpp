#include "Game.h"
#include <iostream>

int main() {
    int maxRange;

    std::cout << "Enter the maximum number for the game: ";
    std::cin >> maxRange;
    // Create Game object
    Game game(maxRange);
    game.play();
    game.printGameResult();

    return 0;
}
