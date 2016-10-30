#include "Player.h"

Player::Player(string playerName):
    name(playerName),
    score(0)
{}


void Player::increaseScore()
{
    score++;
    cout << "Score de " << name << " : " << score << endl;
}
