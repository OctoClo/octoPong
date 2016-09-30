#ifndef PONG_H
#define PONG_H

#include <SDL/SDL.h>

#include <string>

#include "Errors.h"
#include "Ball.h"
#include "Paddle.h"
#include "Texture.h"
#include "FPSCounter.h"

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
        void update();
        void render();
        void cleanExit();
        bool loadMedia();

        int screenWidth;
        int screenHeight;
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
