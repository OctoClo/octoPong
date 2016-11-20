#ifndef PLAYER_H
#define PLAYER_H

#include "Texture.h"
#include "Errors.h"

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Player
{
    public:
        Player(string);
        ~Player();

        int getTextWidth();
        int getScore();
        string getName();

        void increaseScore();
        void update();
        void render(int, SDL_Renderer*);
        void reset();

    private:
        string name;
        int score;

        Texture textTexture;
        TTF_Font* textFont;
        SDL_Color* textColor;
        stringstream text;
};

#endif // PLAYER_H
