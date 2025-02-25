#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Button.hpp"
#include "ProgressBar.hpp"

enum class GameState {
    SELECT_TIME,
    READY_TO_PLAY,
    GAME_ONGOING,
    GAME_WON,
    NEW_GAME
};

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void switchPlayer();
    void resetGame();

    SDL_Window* window;
    SDL_Renderer* renderer;
    GameState currentState;
    
    ProgressBar player1Progress;
    ProgressBar player2Progress;
    
    Button switchPlayer1Button;
    Button switchPlayer2Button;
    Button startButton;
    Button stopButton;
    Button timeButton120;
    Button timeButton300;
    
    int currentPlayer;
    float selectedTime;
    float remainingTime;
    bool isGameRunning;
    bool isRunning;
    
    TTF_Font* font;
    
    // Text rendering members
    SDL_Texture* timerTextTexture;
    SDL_Rect timerTextRect;
    SDL_Texture* stateTextTexture;
    SDL_Rect stateTextRect;
}; 