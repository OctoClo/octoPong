#ifndef MENUMAINMANAGER_H
#define MENUMAINMANAGER_H

#include "MenuMain.h"
#include "Utils.h"

#include <SDL/SDL.h>

class MenuMainManager
{
    public:
        void launch();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

        static MenuMainManager* getInstance(SDL_Renderer* renderer);
        static void killInstance();

    private:
        MenuMainManager(SDL_Renderer* renderer);
        ~MenuMainManager() {}

        MenuMain* menu;

        static MenuMainManager* instance;
};

#endif // MENUMAINMANAGER_H
