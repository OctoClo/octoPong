#ifndef PADDLE_H
#define PADDLE_H

#include <SDL/SDL.h>

enum paddleDirection { UPDIR, DOWNDIR, NOTMOVING };

class Paddle
{
    public:
        Paddle(int, int, int, int, int);
        ~Paddle() {}

        int getX();
        int getY();
        int getWidth();
        int getHeight();

        void accelerate(enum paddleDirection);
        void decelerate();
        void update();
        void render(SDL_Renderer*);

    private:
        int x;
        int y;
        int width;
        int height;
        int speed;
        enum paddleDirection direction;
        SDL_Rect* paddleRect;

        int screenHeight;
};

#endif // PADDLE_H
