#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../../include/game/main/GameMainManager.h"
#include "../../include/game/menu/GameMenuManager.h"
#include "Utils.h"

#include <SDL/SDL.h>

#include <iostream>
using namespace std;

class GameManager
{
    public:
        void launch();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

        static GameManager* getInstance(SDL_Renderer*);
        static void killInstance();

    private:
        GameManager(SDL_Renderer*);
        ~GameManager();

        void setStep(enum Step);

        enum Step step;
        GameMainManager* gameMainManager;
        GameMenuManager* gameMenuManager;

        static GameManager* instance;
};

#endif // GAMEMANAGER_H
