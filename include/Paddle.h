#ifndef PADDLE_H
#define PADDLE_H

#include <SDL/SDL.h>

enum directionPaddle { UP, DOWN };

class Paddle
{
    public:
        Paddle(int, int, int, int);
        ~Paddle() {}
        void draw(SDL_Renderer*);
        void movePaddle(enum directionPaddle);

    private:
        int x;
        int y;
        int width;
        int height;
        SDL_Rect* paddleRect;
};

#endif // PADDLE_H
