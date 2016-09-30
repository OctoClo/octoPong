#ifndef BALL_H
#define BALL_H

#include "Texture.h"
#include "Errors.h"

#include <SDL/SDL.h>
#include <cmath>

class Ball
{
    public:
        Ball(int, int, int, int, SDL_Renderer*);
        ~Ball();

        void update();
        void render(SDL_Renderer*);

    private:
        int xCenter;
        int yCenter;
        const int radius = 5;
        int speedX;
        int speedY;
        Texture texture;

        int screenWidth;
        int screenHeight;
};

#endif // BALL_H
