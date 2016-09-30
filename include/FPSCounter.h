#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <sstream>
#include <string>
#include <cmath>

#include "Texture.h"
#include "Errors.h"

class FPSCounter
{
    public:
        FPSCounter(int, int, string, int, int, int, int);
        ~FPSCounter();
        void update();
        void render(SDL_Renderer*);

    private:
        int x;
        int y;
        Texture textTexture;
        TTF_Font* font;
        SDL_Color* textColor;
        stringstream timeText;
        int countedFrames;
};

#endif // FPSCOUNTER_H
