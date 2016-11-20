#ifndef PADDLE_H
#define PADDLE_H

#include "GameComponent.h"
#include "Utils.h"
#include "Errors.h"

#include <SDL/SDL.h>

class Paddle : public GameComponent
{
    public:
        Paddle(SDL_Renderer*);
        ~Paddle() {}

        void init(int, int);
        void update();

        void accelerate(enum Direction);
        void decelerate();

    private:
        void moove(enum Direction);

        int speed;
        enum Direction direction;
};

#endif // PADDLE_H
