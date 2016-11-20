#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "../include/content/Ball.h"
#include "../include/content/Paddle.h"
#include "../include/content/Player.h"
#include "../include/Utils.h"

#include <SDL/SDL.h>

#include <iostream>
using namespace std;

class GameBoard
{
    public:
        GameBoard(int, int, SDL_Renderer*);
        ~GameBoard();

        void init(Player*, Player*);
        void handleInput(SDL_Event);
        enum Direction update();
        void render();

    private:
        void bounceBall();
        bool checkPaddleCollision(enum Direction);
        bool checkBallOutOfScreen(enum Direction);
        void checkPaddleOutOfScreen(Paddle*);

        void drawLines();

        Ball* ball;
        Paddle* paddleL;
        Paddle* paddleR;
        Player* playerL;
        Player* playerR;

        SDL_Renderer* renderer;

        enum Direction ballOutOfScreen;

        int screenWidth;
        int screenHeight;
        const int PLAYER_TEXT_WIDTH = 25;
        int gameBoardHeight;
};

#endif // GAMEBOARD_H
