#ifndef PONG_H
#define PONG_H

#define GLEW_STATIC

#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Errors.h"
#include "Sprite.h"

enum GameState { PLAY, QUIT };

class Pong
{
    public:
        Pong();
        ~Pong();
        void run();

    private:
        void init();
        void gameLoop();
        void processInput();
        void drawGame();
        void finish();

        int screenWidth;
        int screenHeight;
        SDL_Window* window;
        GameState gameState;
        Sprite sprite;
};

#endif // PONG_H
