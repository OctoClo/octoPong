#ifndef PONG_H
#define PONG_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include <sstream>
#include <cmath>

#include "Errors.h"
#include "Ball.h"
#include "Paddle.h"
#include "Texture.h"

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
        bool loadMedia();
        void calculateFPS();
        void renderFPS();

        int screenWidth;
        int screenHeight;
        GameState gameState;
        SDL_Window* window;
        SDL_Surface* windowSurface;
        SDL_Renderer* windowRenderer;
        Ball* ball;
        Paddle* paddleL;
        Paddle* paddleR;
        TTF_Font* font;
        SDL_Color* textColor;
        stringstream timeText;
        Texture FPSTexture;
        int countedFrames;
};

#endif // PONG_H
