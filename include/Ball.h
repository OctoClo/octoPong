#ifndef BALL_H
#define BALL_H

#include <SDL/SDL.h>
#include <cmath>

#include "Texture.h"
#include "Errors.h"

class Ball
{
    public:
        Ball(int, int, SDL_Renderer*);
        ~Ball();
        void render(SDL_Renderer*);

    private:
        int xCenter;
        int yCenter;
        const int radius = 5;
        Texture texture;
};

#endif // BALL_H
