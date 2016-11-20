#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Utils.h"

#include <SDL/SDL.h>

class GameMenu
{
    public:
        GameMenu(SDL_Renderer*);
        ~GameMenu() {}

        void init();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

    private:

};

#endif // GAMEMENU_H
