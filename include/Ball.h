#ifndef BALL_H
#define BALL_H

#include <SDL/SDL.h>
#include <cmath>

class Ball
{
    public:
        Ball(int, int, int);
        ~Ball() {};
        void draw(SDL_Renderer*);

    private:
        int xCenter;
        int yCenter;
        int radius;
};

#endif // BALL_H
