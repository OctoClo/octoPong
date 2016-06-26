#ifndef PONG_H
#define PONG_H

#define GLEW_STATIC

#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Errors.h"
#include "Sprite.h"

enum GameState { play, quit };

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

        SDL_Window* window;
        int screenWidth;
        int screenHeight;
        GameState gameState;
        Sprite sprite;
};

#endif // PONG_H
