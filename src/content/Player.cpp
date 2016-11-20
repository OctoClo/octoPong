#include "../../include/content/Player.h"

Player::Player(string newName):
    name(newName),
    score(0)
{
    string fontPath = "./resources/Dosis-Regular.otf";

    textFont = TTF_OpenFont(fontPath.c_str(), 15);

    if (!textFont)
        fatalError("Error during font loading", TTF);

    textColor = new SDL_Color();
    textColor->r = 255;
    textColor->g = 255;
    textColor->b = 255;
    textColor->a = 255;
}

Player::~Player()
{
    textTexture.free();

    TTF_CloseFont(textFont);
    textFont = NULL;
}

int Player::getTextWidth()
{
    return textTexture.getWidth();
}

void Player::increaseScore()
{
    score++;
}

void Player::update(SDL_Renderer* renderer)
{
    text.str("");
    text << name << " : " << score;

    if (!textTexture.createTextTexture(text.str(), textColor, textFont, renderer))
        fatalError("Unable to create FPS texture");
}

void Player::render(int x, SDL_Renderer* renderer)
{
    textTexture.render(x, 2, renderer);
}
