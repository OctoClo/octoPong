#include "Ball.h"

Ball::Ball(int newXCenter, int newYCenter, int newRadius):
    xCenter(newXCenter),
    yCenter(newYCenter),
    radius(newRadius) {}

void Ball::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Draw the ball (circle)
    for (int y = yCenter - radius ; y < yCenter + radius ; y++)
    {
        int rx = (int) sqrt(this->radius * radius - ( y - yCenter) * ( y - yCenter));
        for (int x = xCenter - rx ; x < xCenter + rx ; x++)
        {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}
