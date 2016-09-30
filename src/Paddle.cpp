#include "Paddle.h"

Paddle::Paddle(int newX, int newY, int newWidth, int newHeight, int screenH):
    x(newX),
    y(newY),
    width(newWidth),
    height(newHeight),
    speed(0),
    screenHeight(screenH)
{
    direction = NOTMOVING;

    paddleRect = new SDL_Rect();
    paddleRect->x = x;
    paddleRect->y = y;
    paddleRect->w = width;
    paddleRect->h = height;
}

Paddle::getX()
{
    return x;
}

Paddle::getY()
{
    return y;
}

Paddle::getWidth()
{
    return width;
}

Paddle::getHeight()
{
    return height;
}

void Paddle::accelerate(enum paddleDirection dir)
{
    speed += 2;
    direction = dir;
}

void Paddle::decelerate()
{
    speed -= 2;
    if (!speed)
        direction = NOTMOVING;
}

void Paddle::update()
{
    switch (direction)
    {
    case NOTMOVING:
        break;

    case UPDIR:
        if (y > 5)
            y -= speed;
        break;

    case DOWNDIR:
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
