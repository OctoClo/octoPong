#include "../../include/content/GameComponent.h"

GameComponent::GameComponent(SDL_Renderer* renderer, string spritePath)
{
    if (!texture.createImageTexture(spritePath, renderer))
        fatalError("Error during texture creation", IMG);
}

GameComponent::~GameComponent()
{
    texture.free();
}

int GameComponent::getWidth()
{
    return texture.getWidth();
}

int GameComponent::getHeight()
{
    return texture.getHeight();
}

void GameComponent::init(int newX, int newY)
{
    x = newX;
    y = newY;
}

void GameComponent::render(SDL_Renderer* renderer)
{
    texture.render(x, y, renderer);
}
