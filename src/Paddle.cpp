#include "Paddle.h"

Paddle::Paddle(int newX, int newY, int newWidth, int newHeight):
    x(newX),
    y(newY),
    width(newWidth),
    height(newHeight) {}

void Paddle::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Set color to white

    // Draw the ball (circle)
    SDL_Rect* paddleRect = new SDL_Rect();
    paddleRect->x = x;
    paddleRect->y = y;
    paddleRect->w = width;
    paddleRect->h = height;
    SDL_RenderDrawRect(renderer, paddleRect);

    SDL_RenderPresent(renderer);
}
