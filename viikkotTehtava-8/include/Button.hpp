#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Button {
public:
    Button();
    Button(const std::string& text, const SDL_Point& position, const SDL_Point& size);
    
    void setFont(TTF_Font* font);
    void setText(const std::string& text);
    void setPosition(const SDL_Point& position);
    void setSize(const SDL_Point& size);
    void setActive(bool active);
    
    bool isMouseOver(const SDL_Point& mousePos) const;
    void draw(SDL_Renderer* renderer);
    
private:
    SDL_Rect rect;
    std::string text;
    TTF_Font* font;
    SDL_Color textColor;
    bool isActive;
}; 