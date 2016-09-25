#ifndef PADDLE_H
#define PADDLE_H

#include <SDL/SDL.h>

class Paddle
{
    public:
        Paddle(int, int, int, int);
        ~Paddle() {}
        void draw(SDL_Renderer*);

    private:
        int x;
        int y;
        int width;
        int height;
};

#endif // PADDLE_H
