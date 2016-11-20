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

    text.str("");
    text << name << " : " << score;
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

int Player::getScore()
{
    return score;
}

string Player::getName()
{
    return name;
}

void Player::increaseScore()
{
    score++;
}

void Player::update()
{
    text.str("");
    text << name << " : " << score;
}

void Player::render(int x, SDL_Renderer* renderer)
{
    if (!textTexture.createTextTexture(text.str(), textColor, textFont, renderer))
        fatalError("Unable to create FPS texture");
    textTexture.render(x, 2, renderer);
}

void Player::reset()
{
    score = 0;
}
