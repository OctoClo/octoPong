#include "Paddle.h"

Paddle::Paddle(int newX, int newY, int newWidth, int newHeight, int screenH):
    x(newX),
    y(newY),
    width(newWidth),
    height(newHeight),
    speed(0),
    screenHeight(screenH)
{
    direction = NONE;

    paddleRect = new SDL_Rect();
    paddleRect->x = x;
    paddleRect->y = y;
    paddleRect->w = width;
    paddleRect->h = height;
}

void Paddle::accelerate(int vel, enum paddleDirection dir)
{
    speed += vel;
    direction = dir;
}

void Paddle::decelerate(int vel)
{
    speed -= vel;
    if (!speed)
        direction = NONE;
}

void Paddle::update()
{
    switch (direction)
    {
    case NONE:
        break;

    case UP:
        if (y > 5)
            y -= speed;
        break;

    case DOWN:
        if (y < screenHeight - height - 5)
            y += speed;
        break;
    }
}

void Paddle::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    paddleRect->y = y;

    SDL_RenderDrawRect(renderer, paddleRect);
}
