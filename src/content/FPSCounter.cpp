#include "../../include/content/FPSCounter.h"

FPSCounter::FPSCounter(int newX, int newY, string fontPath, int textSize, int r, int g, int b):
    x(newX),
    y(newY)
{
    font = TTF_OpenFont(fontPath.c_str(), textSize);

    if (!font)
        fatalError("Error during font loading", TTF);

    textColor = new SDL_Color();
    textColor->r = r;
    textColor->g = g;
    textColor->b = b;
    textColor->a = 255;

    countedFrames = 0;
}

FPSCounter::~FPSCounter()
{
    textTexture.free();

    TTF_CloseFont(font);
    font = NULL;
}

void FPSCounter::update()
{
    float averageFPS = countedFrames / (SDL_GetTicks() / 1000.f);

    if (averageFPS > 2000000)
    {
        averageFPS = 0;
    }

    timeText.str("");
    timeText << "Average Frames Per Second " << round(averageFPS);

    countedFrames++;
}

void FPSCounter::render(SDL_Renderer* renderer)
{
    if (!textTexture.createTextTexture(timeText.str(), textColor, font, renderer))
        fatalError("Unable to create FPS texture");

    textTexture.render(x, y, renderer);
}
