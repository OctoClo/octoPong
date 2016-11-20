#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "main/MenuMainManager.h"

#include <SDL/SDL.h>

enum MenuStep { MENU_MAIN };

class MenuManager
{
    public:
        static MenuManager* getInstance();
        static void killInstance();

        void setStep(enum MenuStep);

        void launch();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*); // Vraiment besoin du renderer là ?

    private:
        MenuManager();
        ~MenuManager();

        static MenuManager* instance;

        enum MenuStep step;

        MenuMainManager* menuMainManager;
};

#endif // MENUMANAGER_H
