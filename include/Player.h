#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class Player
{
    public:
        Player(string);
        ~Player() {}

        void increaseScore();

    private:
        string name;
        int score;
};

#endif // PLAYER_H
