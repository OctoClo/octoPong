#include "Ball.h"

Ball::Ball():
    xCenter(0),
    yCenter(0),
    radius(0)
{}

void Ball::init(int newXCenter, int newYCenter, int newRadius)
{
    this->xCenter = newXCenter;
    this->yCenter = newYCenter;
    this->radius = newRadius;
}

void Ball::draw(SDL_Renderer* renderer)
{
    // Set color to white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Draw the ball (circle)
    for (int y = this->yCenter - this->radius ; y < this->yCenter + this->radius ; y++)
    {
        int rx = (int) sqrt(this->radius * this->radius - ( y - this->yCenter) * ( y - this->yCenter));
        for (int x = this->xCenter - rx ; x < this->xCenter + rx ; x++)
        {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    //Update screen
    SDL_RenderPresent(renderer);
}
