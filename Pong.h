#ifndef PONG_H
#define PONG_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_net.h>

#include "Errors.h"
#include "Ball.h"

enum GameState { PLAY, QUIT };

class Pong
{
    public:
        Pong();
        ~Pong() {}
        void run();

    private:
        void init();
        void gameLoop();
        void processInput();
        void drawGame();
        void cleanExit();

        int screenWidth;
        int screenHeight;
        GameState gameState;
        SDL_Window* window;
        SDL_Surface* windowSurface;
        SDL_Renderer* windowRenderer;
        Ball* ball;
};

#endif // PONG_H
