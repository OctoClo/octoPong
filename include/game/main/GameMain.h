#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include "Menu.h"
#include "content/Ball.h"
#include "content/Paddle.h"
#include "content/Player.h"
#include "Utils.h"

#include <SDL/SDL.h>

#include <iostream>
using namespace std;

class GameMain
{
    public:
        GameMain(SDL_Renderer*);
        ~GameMain() {}

        void init();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

    private:
        void bounceBall();
        bool checkPaddleCollision(enum Direction);
        bool checkBallOutOfScreen(enum Direction);
        void checkPaddleOutOfScreen(Paddle*);
        void updateScores();
        enum Step checkScores();

        void drawLines(SDL_Renderer*);

        void reset();

        Ball* ball;
        Paddle* paddleL;
        Paddle* paddleR;
        Player* playerL;
        Player* playerR;

        enum Direction ballOutOfScreen;

        const int PLAYER_TEXT_WIDTH = 25;
        int gameBoardHeight;
};

#endif // GAMEMAIN_H
