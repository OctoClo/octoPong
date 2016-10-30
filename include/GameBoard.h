#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Ball.h"
#include "Paddle.h"

#include <SDL/SDL.h>

enum BallOutOfScreen { LEFTOUT, RIGHTOUT, NOTOUT };

class GameBoard
{
    public:
        GameBoard(int, int, SDL_Renderer*);
        ~GameBoard();

        void init();
        void handleInput(SDL_Event);
        enum BallOutOfScreen update();
        void render();

    private:
        void bounceBall();
        void checkBallOutOfScreen();
        void checkPaddleOutOfScreen(Paddle*);

        Ball* ball;
        Paddle* paddleL;
        Paddle* paddleR;

        SDL_Renderer* renderer;

        enum BallOutOfScreen ballOutOfScreen;

        int screenWidth;
        int screenHeight;
};

#endif // GAMEBOARD_H
