#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include "Texture.h"
#include "Errors.h"

#include <SDL/SDL.h>

#include <string>

class GameComponent
{
    public:
        GameComponent(SDL_Renderer*, string);
        virtual ~GameComponent();

        int getX() { return x; }
        void setX(int newX) { x = newX; }
        int getY() { return y; }
        void setY(int newY) { y = newY; }
        int getWidth();
        int getHeight();

        virtual void init(int, int);
        virtual void update() {}
        void render(SDL_Renderer*);

    protected:
        int x;
        int y;

        Texture texture;
};

#endif // GAMECOMPONENT_H
