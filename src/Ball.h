#ifndef BALL_H
#define BALL_H

#include <SDL/SDL.h>
#include <cmath>
#include <cstdlib>

#include <iostream>
using namespace std;

class Ball
{
    public:
        Ball();
        ~Ball();
        void init(int, int, int);
        void draw(SDL_Renderer*);

    private:
        int xCenter;
        int yCenter;
        int radius;
};

#endif // BALL_H
