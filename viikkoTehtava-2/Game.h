#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    // Constructor
    Game(int maxNumber);
    // Destructor
    ~Game();
    void play();
    void printGameResult();
};

#endif
