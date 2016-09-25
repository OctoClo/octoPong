#ifndef ERRORS_H
#define ERRORS_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_net.h>
#include <cstdlib>

#include <iostream>
using namespace std;

enum libraryError { SDL, TTF, IMG, MIX, NET };

void fatalError(const string, enum libraryError = SDL);

#endif // ERRORS_H
