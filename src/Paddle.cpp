#include "Paddle.h"

Paddle::Paddle(int newWidth, int newHeight):
    width(newWidth),
    height(newHeight)
{
    paddleRect = new SDL_Rect();

    paddleRect->w = width;
    paddleRect->h = height;
}

void Paddle::init(int x, int y)
{
    GameComponent::init(x, y);

    paddleRect->x = x;
    paddleRect->y = y;

    speed = 0;
    direction = NOTMOVING;
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

void Paddle::moove(enum paddleDirection dir)
{
    switch (dir)
    {
    case NOTMOVING:
        break;

    case UPDIR:
        y -= speed;
        break;

    case DOWNDIR:
        y += speed;
        break;
    }
}

void Paddle::update()
{
    moove(direction);
}

void Paddle::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    paddleRect->y = y;

    SDL_RenderDrawRect(renderer, paddleRect);
}
