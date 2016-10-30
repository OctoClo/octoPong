#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include <SDL/SDL.h>

class GameComponent
{
    public:
        GameComponent() {}
        virtual ~GameComponent() {}

        virtual int getX() { return x; }
        virtual int getY() { return y; }

        virtual void init(int, int);
        virtual void update() = 0;
        virtual void render(SDL_Renderer*) = 0;

    protected:
        int x;
        int y;
};

#endif // GAMECOMPONENT_H
