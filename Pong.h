#ifndef PONG_H
#define PONG_H

#include "Errors.h"

enum GameState { play, exit };

class Pong
{
    public:
        Pong();
        void run();
        ~Pong();

    private:
        void init();
        void gameLoop();
        void processInput();
        void drawGame();
        void finish();

        SDL_Window* window;
        int screenWidth;
        int screenHeight;
        GameState gameState;
};

#endif // PONG_H
