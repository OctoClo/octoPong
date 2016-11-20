#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include "Errors.h"
#include "Utils.h"
#include "menu/MenuManager.h"
#include "game/GameManager.h"

#include <SDL/SDL.h>

#include <iostream>
using namespace std;

enum MainStep { MENU, GAME, QUIT };

class MainManager
{
    public:
        static MainManager* getInstance();
        static void killInstance();

        enum MainStep getStep();

        void handleEvents(SDL_Event);
        void update();
        void render();

    private:
        MainManager();
        ~MainManager();

        void initSDLSystems();
        void setStep(enum MainStep);

        static MainManager* instance;

        enum MainStep step;

        SDL_Window* window;
        SDL_Renderer* renderer;

        MenuManager* menuManager;
        GameManager* gameManager;
};

#endif // MAINMANAGER_H
