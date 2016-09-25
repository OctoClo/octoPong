#ifndef ERRORS_H
#define ERRORS_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <cstdlib>

#include <iostream>
using namespace std;

enum libraryError { SDL, TTF, IMG };

void fatalError(const string, enum libraryError = SDL);

#endif // ERRORS_H
