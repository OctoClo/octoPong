#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "Texture.h"
#include "Errors.h"

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <cmath>
#include <string>
#include <sstream>
using namespace std;

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
