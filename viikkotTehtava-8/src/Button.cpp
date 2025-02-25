#include "Button.hpp"

Button::Button() : isActive(true), font(nullptr) {
    rect = {0, 0, 0, 0};
    textColor = {0, 0, 0, 255};
}

Button::Button(const std::string& buttonText, const SDL_Point& position, const SDL_Point& size) : Button() {
    setText(buttonText);
    setPosition(position);
    setSize(size);
}

void Button::setFont(TTF_Font* newFont) {
    font = newFont;
}

void Button::setText(const std::string& buttonText) {
    text = buttonText;
}

void Button::setPosition(const SDL_Point& position) {
    rect.x = position.x;
    rect.y = position.y;
}

void Button::setSize(const SDL_Point& size) {
    rect.w = size.x;
    rect.h = size.y;
}

void Button::setActive(bool active) {
    isActive = active;
    if (active) {
        textColor = {0, 0, 0, 255};
    } else {
        textColor = {100, 100, 100, 255};
    }
}

bool Button::isMouseOver(const SDL_Point& mousePos) const {
    return isActive && SDL_PointInRect(&mousePos, &rect);
}

void Button::draw(SDL_Renderer* renderer) {
    // Draw button background
    if (isActive) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    }
    SDL_RenderFillRect(renderer, &rect);
    
    // Draw button border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
    
    // Draw text
    if (font && !text.empty()) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textColor);
        if (surface) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            if (texture) {
                SDL_Rect textRect = {
                    rect.x + (rect.w - surface->w) / 2,
                    rect.y + (rect.h - surface->h) / 2,
                    surface->w,
                    surface->h
                };
                SDL_RenderCopy(renderer, texture, NULL, &textRect);
                SDL_DestroyTexture(texture);
            }
            SDL_FreeSurface(surface);
        }
    }
} 