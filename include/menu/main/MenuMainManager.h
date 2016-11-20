#ifndef MENUMAINMANAGER_H
#define MENUMAINMANAGER_H

#include "MenuMain.h"

#include <SDL/SDL.h>

class MenuMainManager
{
    public:
        static MenuMainManager* getInstance();
        static void killInstance();

        void launch();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*); // Vraiment besoin du renderer là ?

    private:
        MenuMainManager();
        ~MenuMainManager() {}

        static MenuMainManager* instance;

        MenuMain* menu;
};

#endif // MENUMAINMANAGER_H
