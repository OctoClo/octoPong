#ifndef MENUMAIN_H
#define MENUMAIN_H

#include <SDL/SDL.h>

class MenuMain
{
    public:
        MenuMain();
        ~MenuMain() {}

        void init();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*);

    private:

};

#endif // MENUMAIN_H
