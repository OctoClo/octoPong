#include "Texture.h"

Texture::Texture():
    texture(NULL),
    width(0),
    height(0) {}

Texture::~Texture()
{
    free();
}

int Texture::getWidth()
{
	return width;
}

int Texture::getHeight()
{
	return height;
}

bool Texture::createImageTexture(string imagePath, SDL_Renderer* renderer)
{
    bool success = true;

    free();

	SDL_Surface* imageSurface = IMG_Load(imagePath.c_str());
	if (!imageSurface)
		success = false;

    SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface->format, 0, 0xFF, 0xFF));

    texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    if (!texture)
        success = false;

    width = imageSurface->w;
    height = imageSurface->h;

    SDL_FreeSurface(imageSurface);

	return success;
}

bool Texture::createTextTexture(string textureText, SDL_Color* textColor, TTF_Font* font, SDL_Renderer* renderer)
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

void Texture::render(int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect* renderRect = new SDL_Rect;
	renderRect->x = x;
    renderRect->y = y;
	renderRect->w = width;
	renderRect->h = height;

	SDL_RenderCopyEx(renderer, texture, NULL, renderRect, 0.0, NULL, SDL_FLIP_NONE);
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
