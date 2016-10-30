#ifndef PADDLE_H
#define PADDLE_H

#include "GameComponent.h"

#include <SDL/SDL.h>

enum paddleDirection { UPDIR, DOWNDIR, NOTMOVING };

class Paddle : GameComponent
{
    public:
        Paddle(int, int);
        ~Paddle() {}

        int getX() { return GameComponent::getX(); }
        int getY() { return GameComponent::getY(); }
        int getWidth() { return width; }
        int getHeight() { return height; }

        void init(int, int);
        void update();
        void render(SDL_Renderer*);

        void accelerate(enum paddleDirection);
        void decelerate();
        void moove(enum paddleDirection);

    private:
        int width;
        int height;
        int speed;
        enum paddleDirection direction;
        SDL_Rect* paddleRect;
};

#endif // PADDLE_H
