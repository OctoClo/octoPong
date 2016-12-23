#include "Button.h"

Button::Button(SDL_Renderer* renderer, string spritePath):
    GameComponent(renderer, spritePath)
{}

void Button::init(int newX, int newY)
{
    GameComponent::init(newX, newY);

    selected = false;
}

void Button::update()
{
    // nothing to do :)
}
