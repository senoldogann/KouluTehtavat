#include "Game.hpp"
#include <sstream>

Game::Game() : 
    currentState(GameState::SELECT_TIME),
    currentPlayer(1),
    selectedTime(0),
    remainingTime(0),
    isGameRunning(false),
    isRunning(true)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle SDL initialization error
    }
    
    if (TTF_Init() < 0) {
        // Handle TTF initialization error
    }

    window = SDL_CreateWindow("Two Player Game", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);
        
    renderer = SDL_CreateRenderer(window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        
    // Load font
    font = TTF_OpenFont("/System/Library/Fonts/Helvetica.ttc", 24);
    if (!font) {
        // Handle font loading error
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }

    // Initialize progress bars
    player1Progress = ProgressBar({100, 50}, {200, 30});
    player2Progress = ProgressBar({500, 50}, {200, 30});

    // Initialize buttons
    switchPlayer1Button = Button("Switch player", {100, 100}, {120, 40});
    switchPlayer2Button = Button("Switch player", {500, 100}, {120, 40});
    startButton = Button("START GAME", {300, 500}, {120, 40});
    stopButton = Button("STOP GAME", {450, 500}, {120, 40});
    timeButton120 = Button("120 sec", {250, 400}, {100, 40});
    timeButton300 = Button("5 min", {400, 400}, {100, 40});

    // Set fonts for all buttons
    switchPlayer1Button.setFont(font);
    switchPlayer2Button.setFont(font);
    startButton.setFont(font);
    stopButton.setFont(font);
    timeButton120.setFont(font);
    timeButton300.setFont(font);

    resetGame();
}

Game::~Game() {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();
    
    while (isRunning) {
        processEvents();
        
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        
        if (isGameRunning && remainingTime > 0) {
            remainingTime -= deltaTime;
            if (remainingTime <= 0) {
                currentState = GameState::GAME_WON;
                isGameRunning = false;
            }
        }
        
        update();
        render();
    }
}

void Game::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_Point mousePos = {event.button.x, event.button.y};
            
            if (currentState == GameState::SELECT_TIME) {
                if (timeButton120.isMouseOver(mousePos)) {
                    selectedTime = 120;
                    remainingTime = selectedTime;
                    currentState = GameState::READY_TO_PLAY;
                }
                else if (timeButton300.isMouseOver(mousePos)) {
                    selectedTime = 300;
                    remainingTime = selectedTime;
                    currentState = GameState::READY_TO_PLAY;
                }
            }
            
            if (startButton.isMouseOver(mousePos)) {
                if (currentState == GameState::READY_TO_PLAY || currentState == GameState::NEW_GAME) {
                    currentState = GameState::GAME_ONGOING;
                    isGameRunning = true;
                }
            }
            
            if (stopButton.isMouseOver(mousePos)) {
                if (currentState == GameState::GAME_ONGOING) {
                    currentState = GameState::NEW_GAME;
                    isGameRunning = false;
                }
            }
            
            if (isGameRunning) {
                if (currentPlayer == 1 && switchPlayer1Button.isMouseOver(mousePos)) {
                    switchPlayer();
                }
                else if (currentPlayer == 2 && switchPlayer2Button.isMouseOver(mousePos)) {
                    switchPlayer();
                }
            }
        }
    }
}

void Game::update() {
    std::stringstream ss;
    ss << static_cast<int>(remainingTime) << " seconds";
    
    // Render timer text
    SDL_Color textColor = {0, 0, 0, 255};
    SDL_Surface* timerSurface = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);
    SDL_Texture* timerTexture = SDL_CreateTextureFromSurface(renderer, timerSurface);
    SDL_Rect timerRect = {350, 200, timerSurface->w, timerSurface->h};
    SDL_FreeSurface(timerSurface);
    
    // Render state text
    const char* stateStr = "";
    switch (currentState) {
        case GameState::SELECT_TIME:
            stateStr = "Select playtime and press start game!";
            break;
        case GameState::READY_TO_PLAY:
            stateStr = "Ready to play";
            break;
        case GameState::GAME_ONGOING:
            stateStr = "Game ongoing";
            break;
        case GameState::GAME_WON:
            ss.str("");
            ss << "Player " << currentPlayer << " WON!!";
            stateStr = ss.str().c_str();
            break;
        case GameState::NEW_GAME:
            stateStr = "New game via start button";
            break;
    }
    
    SDL_Surface* stateSurface = TTF_RenderText_Solid(font, stateStr, textColor);
    SDL_Texture* stateTexture = SDL_CreateTextureFromSurface(renderer, stateSurface);
    SDL_Rect stateRect = {300, 150, stateSurface->w, stateSurface->h};
    SDL_FreeSurface(stateSurface);
    
    // Store textures and rects for rendering
    timerTextTexture = timerTexture;
    timerTextRect = timerRect;
    stateTextTexture = stateTexture;
    stateTextRect = stateRect;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    player1Progress.draw(renderer);
    player2Progress.draw(renderer);
    
    switchPlayer1Button.draw(renderer);
    switchPlayer2Button.draw(renderer);
    startButton.draw(renderer);
    stopButton.draw(renderer);
    
    if (currentState == GameState::SELECT_TIME) {
        timeButton120.draw(renderer);
        timeButton300.draw(renderer);
    }
    
    // Render text textures
    if (timerTextTexture) {
        SDL_RenderCopy(renderer, timerTextTexture, NULL, &timerTextRect);
        SDL_DestroyTexture(timerTextTexture);
        timerTextTexture = nullptr;
    }
    
    if (stateTextTexture) {
        SDL_RenderCopy(renderer, stateTextTexture, NULL, &stateTextRect);
        SDL_DestroyTexture(stateTextTexture);
        stateTextTexture = nullptr;
    }
    
    SDL_RenderPresent(renderer);
}

void Game::switchPlayer() {
    if (currentPlayer == 1) {
        currentPlayer = 2;
        player1Progress.setProgress(player1Progress.getProgress() + 10);
    } else {
        currentPlayer = 1;
        player2Progress.setProgress(player2Progress.getProgress() + 10);
    }
}

void Game::resetGame() {
    player1Progress.setProgress(0);
    player2Progress.setProgress(0);
    currentPlayer = 1;
    remainingTime = selectedTime;
    isGameRunning = false;
} 