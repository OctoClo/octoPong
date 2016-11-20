#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include <SDL/SDL.h>

class GameMain
{
    public:
        GameMain();
        ~GameMain() {}

        void init();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*);

    private:

};

#endif // GAMEMAIN_H
