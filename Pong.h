#ifndef PONG_H
#define PONG_H

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <iostream>
using namespace std;

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
        void finish();

        SDL_Window* window;
        int screenWidth;
        int screenHeight;
        GameState gameState;
};

#endif // PONG_H
