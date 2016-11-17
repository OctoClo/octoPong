#ifndef PONG_H
#define PONG_H

#include "GameBoard.h"
#include "Player.h"
#include "Errors.h"
#include "Utils.h"

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
        void initSDLSystems();
        void initObjects();
        void gameLoop();
        void processInput();
        void update();
        void render();
        void updateScores(enum Direction);
        void cleanExit();

        const int SCREEN_WIDTH = 400;
        const int SCREEN_HEIGHT = 300;

        SDL_Window* window;

        GameState gameState;

        GameBoard* gameBoard;
        Player* playerL;
        Player* playerR;

        //FPSCounter* fpsCounter;
        //string fontPath;
};

#endif // PONG_H
