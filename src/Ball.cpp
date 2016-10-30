#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer)
{
    if (!texture.createImageTexture("./resources/Ball.png", renderer))
        fatalError("Error during ball texture creation", IMG);
}

Ball::~Ball()
{
    texture.free();
}

void Ball::init(int x, int y)
{
    GameComponent::init(x, y);

    speedX = 2;
    speedY = -1;
}

void Ball::update()
{
    x += speedX;
    y += speedY;
}

void Ball::render(SDL_Renderer* renderer)
{
    texture.render(x - radius, y - radius, renderer);
}
