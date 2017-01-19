#ifndef MENUMAIN_H
#define MENUMAIN_H

#include "Menu.h"
#include "Button.h"
#include "Utils.h"

#include <SDL/SDL.h>

#include <iostream>
using namespace std;

class MenuMain : public Menu
{
    public:
        MenuMain(SDL_Renderer*);
        ~MenuMain() {}

        void init();
        void handleEvents(SDL_Event);
        enum Step update();
        void render(SDL_Renderer*);

    private:
        void updateButtonSelection();

        int selection;
        int launched;

        GameComponent* buttonSelection;
};

#endif // MENUMAIN_H
