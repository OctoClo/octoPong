#include "Ball.h"

Ball::Ball(int screenW, int screenH, SDL_Renderer* renderer):
    speedX(2),
    speedY(1),
    screenWidth(screenW),
    screenHeight(screenH)

{
    if (!texture.createImageTexture("./resources/Ball.png", renderer))
        fatalError("Error during ball texture creation", IMG);

    init();
}

Ball::~Ball()
{
    texture.free();
}

bool Ball::isOffScreen()
{
    return offScreen;
}

enum SideOut Ball::getSideOut()
{
    return sideOut;
}

void Ball::init()
{
    xCenter = screenWidth / 2;
    yCenter = screenHeight / 2;
    offScreen = false;
    sideOut = NOTOUT;
}

void Ball::update(Paddle* paddleL, Paddle* paddleR)
{
    xCenter += speedX;
    yCenter += speedY;

    // Bouncing on top & bottom of the screen
    if (yCenter + radius >= screenHeight || yCenter <= radius)
        speedY = -speedY;

    // Bouncing on the left paddle
    if (xCenter - radius <= paddleL->getX() + paddleL->getWidth() // Checking x axis
            &&
        yCenter - radius <= paddleL->getY() + paddleL->getHeight() // Checking bottom y axis
            &&
        yCenter + radius >= paddleL->getY()) // Checking top y axis
        speedX = -speedX;

    // Bouncing on the right paddle
    if (xCenter + radius >= paddleR->getX() // Checking x axis
            &&
        yCenter - radius <= paddleR->getY() + paddleR->getHeight() // Checking bottom y axis
            &&
        yCenter + radius >= paddleR->getY()) // Checking top y axis
        speedX = -speedX;

    // Checking if off screen
    if (xCenter - radius > screenWidth)
    {
        offScreen = true;
        sideOut = RIGHTOUT;
    }
    else if (xCenter + radius < 0)
    {
        offScreen = true;
        sideOut = LEFTOUT;
    }

}

void Ball::render(SDL_Renderer* renderer)
{
    texture.render(xCenter - radius, yCenter - radius, renderer);
}
