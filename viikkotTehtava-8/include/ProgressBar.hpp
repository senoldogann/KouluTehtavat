#pragma once
#include <SDL2/SDL.h>

class ProgressBar {
public:
    ProgressBar();
    ProgressBar(const SDL_Point& position, const SDL_Point& size);
    
    void setPosition(const SDL_Point& position);
    void setSize(const SDL_Point& size);
    void setProgress(float percentage);
    float getProgress() const;
    void draw(SDL_Renderer* renderer);
    
private:
    SDL_Rect background;
    SDL_Rect fill;
    float progress;
}; 