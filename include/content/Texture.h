#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include <iostream>
#include <string>
using namespace std;

class Texture
{
    public:
        Texture();
        ~Texture();

        int getWidth();
		int getHeight();

		bool createImageTexture(string, SDL_Renderer*);
		bool createTextTexture(string, SDL_Color*, TTF_Font*, SDL_Renderer*);
		void render(int, int, SDL_Renderer*);
		void free();

    private:
		SDL_Texture* texture;
		int width;
		int height;
};

#endif // TEXTURE_H
