#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor
Game::Game(int maxNumber) : maxNumber(maxNumber), playerGuess(0), numOfGuesses(0) {
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    std::cout << "GAME CONSTRUCTOR: Object initialized with " << maxNumber << " as maximum value." << std::endl;
}

// Destructor
Game::~Game() {
    std::cout << "Game finished lets clean memory :)." << std::endl;
}

// Play method
void Game::play() {
    std::cout << "Give your guess between 1-" << maxNumber << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            std::cout << "Your guess is too small." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Your guess is too big." << std::endl;
        }
    } while (playerGuess != randomNumber);

    std::cout << "Your guess is right = " << randomNumber << std::endl;
}

// Print game result
void Game::printGameResult() {
    std::cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses." << std::endl;
}
