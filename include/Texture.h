#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <string>
using namespace std;

class Texture
{
    public:
        Texture();
        ~Texture();

		bool loadFromRenderedText(string, SDL_Color*, TTF_Font*, SDL_Renderer*);
		void free();
		void draw(int, int, SDL_Renderer*);
		int getWidth();
		int getHeight();

    private:
		SDL_Texture* texture;
		int width;
		int height;
};

#endif // TEXTURE_H
