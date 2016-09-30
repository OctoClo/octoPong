#include "Ball.h"

Ball::Ball(int newXCenter, int newYCenter, SDL_Renderer* renderer):
    xCenter(newXCenter),
    yCenter(newYCenter)
{
    if (!texture.createImageTexture("./resources/Ball.png", renderer))
        fatalError("Error during ball texture creation", IMG);
}

Ball::~Ball()
{
    texture.free();
}

void Ball::render(SDL_Renderer* renderer)
{
    texture.render(xCenter - radius, yCenter - radius, renderer);
}
