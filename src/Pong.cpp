#include "Pong.h"

Pong::Pong():
    screenWidth(400),
    screenHeight(300),
    window(nullptr),
    gameState(PLAY),
    sprite()
{}

Pong::~Pong()
{
}

void Pong::run()
{
    this->init();
    this->gameLoop();
    this->finish();
}

void Pong::init()
{
    // Initialize everything needed by SDL, catch the eventual error
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        fatalError("Error in SDL init");

    // Open the window
    this->window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->screenWidth, this->screenHeight, SDL_WINDOW_OPENGL);
    if (!window)
        fatalError("Error in window creation");
}

void Pong::gameLoop()
{
    // Process inputs while there is no exit
    while (this->gameState != QUIT)
    {
        this->processInput();
        this-> drawGame();
    }
}

void Pong::processInput()
{
    SDL_Event evnt;

    while (SDL_PollEvent(&evnt))
    {
        switch (evnt.type)
        {
            case SDL_QUIT:
                this->gameState = QUIT;
                break;

            case SDL_MOUSEMOTION:
                cout << evnt.motion.x << " ; " << evnt.motion.y << endl; // Display x and y coordinates
                break;

            case SDL_KEYDOWN:
                if (evnt.key.keysym.sym == SDLK_ESCAPE)
                    this->gameState = QUIT;
                break;

            default:
                break;
        }
    }
}

void Pong::drawGame()
{

}

void Pong::finish()
{
    // Destroy the window
    SDL_DestroyWindow(window);
    window = nullptr;

    // Quit everything SDL created
    SDL_Quit();
}
