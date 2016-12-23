#ifndef MENU_H
#define MENU_H

#include "content/GameComponent.h"
#include "Utils.h"

#include <SDL/SDL.h>

#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Menu
{
    public:
        virtual void init() = 0;
        virtual void handleEvents(SDL_Event) = 0;
        virtual enum Step update();
        virtual void render(SDL_Renderer*);

    protected:
        vector<GameComponent*> components;

    private:
};

#endif // MENU_H
