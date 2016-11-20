#ifndef MENUMAIN_H
#define MENUMAIN_H

#include "Utils.h"

#include <SDL/SDL.h>

class MenuMain
{
    public:
        MenuMain(SDL_Renderer* renderer);
        ~MenuMain() {}

        void init();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

    private:

};

#endif // MENUMAIN_H
