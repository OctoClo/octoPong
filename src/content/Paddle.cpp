#include "../../include/content/Paddle.h"

Paddle::Paddle(SDL_Renderer* renderer):
    GameComponent(renderer, "./resources/Paddle.png")
{}

void Paddle::init(int newX, int newY)
{
    GameComponent::init(newX, newY);

    speed = 0;
    direction = NONE;
}

void Paddle::accelerate(enum Direction dir)
{
    speed = 2;
    direction = dir;
}

void Paddle::decelerate()
{
    speed = 0;
    direction = NONE;
}

void Paddle::moove(enum Direction dir)
{
    switch (dir)
    {
    case NONE:
        break;

    case TOP:
        y -= speed;
        break;

    case BOTTOM:
        y += speed;
        break;

    default:
        fatalError("Direction inattendue dans la fonction moove()");
        break;
    }
}

void Paddle::update()
{
    moove(direction);
}
