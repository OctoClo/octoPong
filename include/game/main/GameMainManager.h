#ifndef GAMEMAINMANAGER_H
#define GAMEMAINMANAGER_H

#include "GameMain.h"

#include <SDL/SDL.h>

class GameMainManager
{
    public:
        static GameMainManager* getInstance();
        static void killInstance();

        void launch();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*); // Vraiment besoin du renderer là ?

    private:
        GameMainManager();
        ~GameMainManager() {}

        static GameMainManager* instance;

        GameMain* game;
};

#endif // GAMEMAINMANAGER_H
