#ifndef GAMEMENUMANAGER_H
#define GAMEMENUMANAGER_H

#include "GameMenu.h"

#include <SDL/SDL.h>

class GameMenuManager
{
    public:
        static GameMenuManager* getInstance();
        static void killInstance();

        void launch();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*); // Vraiment besoin du renderer là ?

    private:
        GameMenuManager();
        ~GameMenuManager() {}

        static GameMenuManager* instance;

        GameMenu* menu;
};

#endif // GAMEMENUMANAGER_H
