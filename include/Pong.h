#ifndef PONG_H
#define PONG_H

#include "GameBoard.h"
#include "Errors.h"
#include "Ball.h"
#include "Player.h"
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

    private:
        void init();
        void gameLoop();
        void processInput();
        void update();
        void render();
        void updateScores(enum BallOutOfScreen);
        void cleanExit();

        const int screenWidth = 400;
        const int screenHeight = 300;

        SDL_Window* window;

        GameState gameState;

        GameBoard* gameBoard;
        Player* playerL;
        Player* playerR;

        //FPSCounter* fpsCounter;
        //string fontPath;
};

#endif // PONG_H
