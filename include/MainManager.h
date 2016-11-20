#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include "menu/MenuManager.h"
#include "game/GameManager.h"
#include "Errors.h"
#include "Utils.h"

#include <SDL/SDL.h>

#include <iostream>
using namespace std;

class MainManager
{
    public:
        enum Step getStep();

        void handleEvents(SDL_Event);
        void update();
        void render();

        static MainManager* getInstance();
        static void killInstance();

    private:
        MainManager();
        ~MainManager();

        void setStep(enum Step);

        void initSDLSystems();

        SDL_Window* window;
        SDL_Renderer* renderer;

        enum Step step;
        MenuManager* menuManager;
        GameManager* gameManager;

        static MainManager* instance;
};

#endif // MAINMANAGER_H
