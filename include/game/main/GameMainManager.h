#ifndef GAMEMAINMANAGER_H
#define GAMEMAINMANAGER_H

#include "GameMain.h"
#include "Utils.h"

#include <SDL/SDL.h>

class GameMainManager
{
    public:
        void launch();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

        static GameMainManager* getInstance(SDL_Renderer*);
        static void killInstance();

    private:
        GameMainManager(SDL_Renderer*);
        ~GameMainManager() {}

        GameMain* game;

        static GameMainManager* instance;
};

#endif // GAMEMAINMANAGER_H
