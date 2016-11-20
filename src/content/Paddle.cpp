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

void Paddle::goDown()
{
    y += speed;
}

void Paddle::goUp()
{
    y -= speed;
}

void Paddle::update()
{
    switch (direction)
    {
    case NONE:
        break;

    case TOP:
        goUp();
        break;

    case BOTTOM:
        goDown();
        break;

    default:
        fatalError("Direction inattendue dans la fonction update() de Paddle");
        break;
    }
}
