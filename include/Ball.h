#ifndef BALL_H
#define BALL_H

#include "GameComponent.h"
#include "Texture.h"
#include "Paddle.h"
#include "Errors.h"

#include <SDL/SDL.h>
#include <cmath>

class Ball : GameComponent
{
    public:
        Ball(SDL_Renderer*);
        ~Ball();

        int getX() { return GameComponent::getX(); }
        int getY() { return GameComponent::getY(); }
        int getRadius() { return radius; }

        void init(int, int);
        void update();
        void render(SDL_Renderer*);

        void invertSpeedX() { speedX = -speedX; }
        void invertSpeedY() { speedY = -speedY; }

    private:
        const int radius = 5;
        int speedX;
        int speedY;
        Texture texture;
};

#endif // BALL_H
