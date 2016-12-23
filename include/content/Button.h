#ifndef BUTTON_H
#define BUTTON_H

#include "GameComponent.h"

#include <SDL/SDL.h>

#include <string>

class Button : public GameComponent
{
    public:
        Button(SDL_Renderer*, string);

        void init(int, int);
        void update();

        void setSelected(bool newSelected) { selected = newSelected; }
        bool getSelected() { return selected; }

    private:
        bool selected;
};

#endif // BUTTON_H
