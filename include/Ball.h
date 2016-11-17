#ifndef BALL_H
#define BALL_H

#include "GameComponent.h"

#include <SDL/SDL.h>

#include <string>

class Ball : public GameComponent
{
    public:
        Ball(SDL_Renderer*);

        int getRadius() { return radius; }
        int getDiameter() { return getWidth(); }

        void init(int, int);
        void update();

        void invertSpeedX() { speedX = -speedX; }
        void invertSpeedY() { speedY = -speedY; }

    private:
        const int radius = 5;
        int speedX;
        int speedY;
};

#endif // BALL_H
