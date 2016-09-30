#ifndef PADDLE_H
#define PADDLE_H

#include <SDL/SDL.h>

enum paddleDirection { UP, DOWN, NONE };

class Paddle
{
    public:
        Paddle(int, int, int, int, int);
        ~Paddle() {}

        void accelerate(int, enum paddleDirection);
        void decelerate(int);
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
