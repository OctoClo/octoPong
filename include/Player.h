#ifndef PLAYER_H
#define PLAYER_H

#include "Paddle.h"

#include <string>
#include <iostream>
using namespace std;

enum PlayerPosition { LEFTPOS, RIGHTPOS };

class Player
{
    public:
        Player(string, enum PlayerPosition, int);
        ~Player() {}

        Paddle* getPaddle();

        void init();
        void handleInput(SDL_Event);
        void update();
        void render(SDL_Renderer*);
        void increaseScore();

    private:
        string name;
        Paddle* paddle;
        enum PlayerPosition position;
        int score;

        int screenHeight;
};

#endif // PLAYER_H
