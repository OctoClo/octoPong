#ifndef SPRITE_H
#define SPRITE_H

#define GLEW_STATIC

#include <GL/glew.h>

class Sprite
{
    public:
        Sprite();
        ~Sprite();
        void init(float, float, float, float);
        void draw();

    private:
        float x;
        float y;
        float width;
        float height;
};

#endif // SPRITE_H
