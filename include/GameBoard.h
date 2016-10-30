#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Ball.h"
#include "Paddle.h"
#include "Player.h"

#include <SDL/SDL.h>

enum BallOutOfScreen { LEFTOUT, RIGHTOUT, NOTOUT };

class GameBoard
{
    public:
        GameBoard(int, int, SDL_Renderer*);
        ~GameBoard();

        void init(Player*, Player*);
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
        Player* playerL;
        Player* playerR;

        SDL_Renderer* renderer;

        enum BallOutOfScreen ballOutOfScreen;

        int screenWidth;
        int screenHeight;
        const int playerTextWidth = 25;
        int gameBoardHeight;
};

#endif // GAMEBOARD_H
