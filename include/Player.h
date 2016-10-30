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

        void increaseScore();
        void update(SDL_Renderer*);
        void render(int, SDL_Renderer*);

    private:
        string name;
        int score;

        Texture textTexture;
        TTF_Font* textFont;
        SDL_Color* textColor;
        stringstream text;
};

#endif // PLAYER_H
