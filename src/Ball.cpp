#include "Ball.h"

Ball::Ball(int newXCenter, int newYCenter, int screenW, int screenH, SDL_Renderer* renderer):
    xCenter(newXCenter),
    yCenter(newYCenter),
    speedX(2),
    speedY(1),
    screenWidth(screenW),
    screenHeight(screenH)

{
    if (!texture.createImageTexture("./resources/Ball.png", renderer))
        fatalError("Error during ball texture creation", IMG);
}

Ball::~Ball()
{
    texture.free();
}

void Ball::update()
{
    xCenter += speedX;
    yCenter += speedY;

    if (xCenter > screenWidth - radius || xCenter < radius)
        speedX = -speedX;

    if (yCenter > screenHeight - radius || yCenter < radius)
        speedY = -speedY;
}

void Ball::render(SDL_Renderer* renderer)
{
    texture.render(xCenter - radius, yCenter - radius, renderer);
}
