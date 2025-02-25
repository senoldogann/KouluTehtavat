#include "Game.hpp"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
    }
    
    if (TTF_Init() < 0) {
        SDL_Quit();
        return 1;
    }
    
    Game game;
    game.run();
    
    TTF_Quit();
    SDL_Quit();
    return 0;
} 