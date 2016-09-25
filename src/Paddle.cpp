#include "Paddle.h"

Paddle::Paddle(int newX, int newY, int newWidth, int newHeight):
    x(newX),
    y(newY),
    width(newWidth),
    height(newHeight)
{
    paddleRect = new SDL_Rect();
    paddleRect->x = x;
    paddleRect->y = y;
    paddleRect->w = width;
    paddleRect->h = height;
}

void Paddle::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    paddleRect->y = y;

    SDL_RenderDrawRect(renderer, paddleRect);
}

void Paddle::movePaddle(enum directionPaddle direction)
{
    switch (direction)
    {
    case UP:
        if (!(y <= 5))
            y -= 5;
        break;
    case DOWN:
        if (!(y >= 245))
            y += 5;
        break;
    }
}
