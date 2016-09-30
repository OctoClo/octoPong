#ifndef BALL_H
#define BALL_H

#include "Texture.h"
#include "Paddle.h"
#include "Errors.h"

#include <SDL/SDL.h>
#include <cmath>

enum SideOut { LEFTOUT, RIGHTOUT, NOTOUT };

class Ball
{
    public:
        Ball(int, int, SDL_Renderer*);
        ~Ball();

        bool isOffScreen();
        enum SideOut getSideOut();

        void init();
        void update(Paddle*, Paddle*);
        void render(SDL_Renderer*);

    private:
        int xCenter;
        int yCenter;
        const int radius = 5;
        int speedX;
        int speedY;
        Texture texture;

        bool offScreen;
        enum SideOut sideOut;

        int screenWidth;
        int screenHeight;
};

#endif // BALL_H
