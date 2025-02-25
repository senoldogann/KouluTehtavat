#include "ProgressBar.hpp"

ProgressBar::ProgressBar() : progress(0) {
    background = {0, 0, 0, 0};
    fill = {0, 0, 0, 0};
}

ProgressBar::ProgressBar(const SDL_Point& position, const SDL_Point& size) : ProgressBar() {
    setPosition(position);
    setSize(size);
}

void ProgressBar::setPosition(const SDL_Point& position) {
    background.x = position.x;
    background.y = position.y;
    fill.x = position.x;
    fill.y = position.y;
}

void ProgressBar::setSize(const SDL_Point& size) {
    background.w = size.x;
    background.h = size.y;
    fill.w = static_cast<int>(size.x * progress / 100.0f);
    fill.h = size.y;
}

void ProgressBar::setProgress(float percentage) {
    progress = percentage;
    if (progress < 0) progress = 0;
    if (progress > 100) progress = 100;
    
    fill.w = static_cast<int>(background.w * progress / 100.0f);
}

float ProgressBar::getProgress() const {
    return progress;
}

void ProgressBar::draw(SDL_Renderer* renderer) {
    // Draw background
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &background);
    
    // Draw fill
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &fill);
} 