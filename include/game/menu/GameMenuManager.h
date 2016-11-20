#ifndef GAMEMENUMANAGER_H
#define GAMEMENUMANAGER_H

#include "GameMenu.h"
#include "Utils.h"

#include <SDL/SDL.h>

class GameMenuManager
{
    public:
        void launch();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

        static GameMenuManager* getInstance(SDL_Renderer*);
        static void killInstance();

    private:
        GameMenuManager(SDL_Renderer*);
        ~GameMenuManager() {}

        GameMenu* menu;

        static GameMenuManager* instance;
};

#endif // GAMEMENUMANAGER_H
