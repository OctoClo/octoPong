#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "main/MenuMainManager.h"
#include "Utils.h"

#include <SDL/SDL.h>

class MenuManager
{
    public:
        void launch();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

        static MenuManager* getInstance(SDL_Renderer*);
        static void killInstance();

    private:
        MenuManager(SDL_Renderer*);
        ~MenuManager();

        void setStep(enum Step);

        enum Step step;
        MenuMainManager* menuMainManager;

        static MenuManager* instance;
};

#endif // MENUMANAGER_H
