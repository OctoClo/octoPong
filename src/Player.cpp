#include "Player.h"

Player::Player(string playerName, enum PlayerPosition pos, int screenH):
    name(playerName),
    position(pos),
    screenHeight(screenH)
{
    init();
}

Paddle* Player::getPaddle()
{
    return paddle;
}

void Player::init()
{
    score = 0;
    if (position == LEFTPOS)
        paddle = new Paddle(10, 125, 10, 50, screenHeight);
    else if (position == RIGHTPOS)
        paddle = new Paddle(380, 125, 10, 50, screenHeight);
}

void Player::handleInput(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_z:
                if (position == LEFTPOS)
                    paddle->accelerate(UPDIR);
                break;

            case SDLK_s:
                if (position == LEFTPOS)
                    paddle->accelerate(DOWNDIR);
                break;

            case SDLK_UP:
                if (position == RIGHTPOS)
                    paddle->accelerate(UPDIR);
                break;

            case SDLK_DOWN:
                if (position == RIGHTPOS)
                    paddle->accelerate(DOWNDIR);
                break;
            }
        }

        else if (event.type == SDL_KEYUP && event.key.repeat == 0)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_z:
            case SDLK_s:
                if (position == LEFTPOS)
                    paddle->decelerate();
                break;

            case SDLK_UP:
            case SDLK_DOWN:
                if (position == RIGHTPOS)
                    paddle->decelerate();
                break;
            }
        }
}

void Player::update()
{
    paddle->update();
}

void Player::render(SDL_Renderer* renderer)
{
    paddle->render(renderer);
}

void Player::increaseScore()
{
    score++;
    cout << "Score de " << name << " : " << score << endl;
}
