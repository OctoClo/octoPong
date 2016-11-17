#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer):
    GameComponent(renderer, "./resources/Ball.png")
{}

void Ball::init(int newX, int newY)
{
    GameComponent::init(newX, newY);

    speedX = 2;
    speedY = -1;
}

void Ball::update()
{
    x += speedX;
    y += speedY;
}
