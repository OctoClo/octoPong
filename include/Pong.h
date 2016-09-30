#ifndef PONG_H
#define PONG_H

#include "Errors.h"
#include "Ball.h"
#include "Paddle.h"
#include "Texture.h"
#include "FPSCounter.h"

#include <SDL/SDL.h>

#include <string>

enum GameState { PLAY, QUIT };

class Pong
{
    public:
        Pong();
        ~Pong() {}

        void run();

        int screenWidth;
        int screenHeight;

    private:
        void init();
        void gameLoop();
        void processInput();
        void update();
        void render();
        void cleanExit();
        bool loadMedia();

        SDL_Window* window;
        SDL_Renderer* windowRenderer;

        GameState gameState;

        Ball* ball;
        Paddle* paddleL;
        Paddle* paddleR;

        FPSCounter* fpsCounter;
        string fontPath;
};

#endif // PONG_H
