#include "Texture.h"

Texture::Texture():
    texture(NULL),
    width(0),
    height(0) {}

Texture::~Texture()
{
    free();
}

bool Texture::loadFromRenderedText(string textureText, SDL_Color* textColor, TTF_Font* font, SDL_Renderer* renderer)
{
	bool success = true;

	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), *textColor);
	if (!textSurface)
        success = false;

    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!texture)
        success = false;

    width = textSurface->w;
    height = textSurface->h;

    SDL_FreeSurface(textSurface);

	return success;
}

void Texture::free()
{
    if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::draw(int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect* renderRect = new SDL_Rect;
	renderRect->x = x;
    renderRect->y = y;
	renderRect->w = width;
	renderRect->h = height;

	SDL_RenderCopyEx(renderer, texture, NULL, renderRect, 0.0, NULL, SDL_FLIP_NONE);
}

int Texture::getWidth()
{
	return width;
}

int Texture::getHeight()
{
	return height;
}
