#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SDL/SDL.h>

class GameMenu
{
    public:
        GameMenu();
        ~GameMenu() {}

        void init();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*);

    private:

};

#endif // GAMEMENU_H
