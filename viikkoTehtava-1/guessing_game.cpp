#include <iostream>
#include <cstdlib>
#include <ctime>

int game() {
    srand(time(0));
    int randomNumber = rand() % 20 + 1;
    int playerGuess;
    int guessCount = 0;

    std::cout << "I'm thinking of a number between 1 and 20. Try to guess number!!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        guessCount++;

        if (playerGuess < randomNumber) {
            std::cout << "Too low! Try a higher number." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Too high! Try a lower number." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
        }
    } while (playerGuess != randomNumber);

    return guessCount;
}

// Function with maxnum parameter
int game(int maxnum) {
    srand(time(0));
    int randomNumber = rand() % maxnum + 1;
    int playerGuess;
    int guessCount = 0;

    std::cout << "I'm thinking of a number between 1 and " << maxnum << ". Try to guess it!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        guessCount++;

        if (playerGuess < randomNumber) {
            std::cout << "Too low! Try a higher number." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Too high! Try a lower number." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
        }
    } while (playerGuess != randomNumber);

    return guessCount;
}

int main() {
    int totalGuesses1 = game();
    std::cout << "Total guesses (range 1-20): " << totalGuesses1 << std::endl;

    int maxNumber;
    std::cout << "Please enter the maximum range for the number: ";
    std::cin >> maxNumber;

    int totalGuesses2 = game(maxNumber);
    std::cout << "Total guesses (range 1-" << maxNumber << "): " << totalGuesses2 << std::endl;

    return 0;
}
