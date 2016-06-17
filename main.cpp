#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

using namespace std;

int main (int argc, char** argv)
{
    // Initialize everything needed by SDL, catch the eventual error
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Error in SDL initialization : " << SDL_GetError();
        return 1;
    }

    // Create a window
    SDL_Window* window;
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    if (!window) // Catch the eventual error
    {
        cout << "Error in window creation : " << SDL_GetError();
        return 1;
    }

    // ---------- OpenGL context test ----------
    /* SDL_GLContext glContext = SDL_GL_CreateContext(window);

    glClearColor(0,0,0,1);

    SDL_GL_DeleteContext(glContext); */

    // Loop until the user closes the window or presses any key
    SDL_Event e;

    SDL_Surface* surface;
    SDL_Renderer* renderer;

    surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateSoftwareRenderer(surface);
    if (!renderer)  // Catch the eventual error
    {
        cout << "Error in renderer creation : " << SDL_GetError();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0xAF, 0x00, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_UpdateWindowSurface(window);
    SDL_DestroyRenderer(renderer);

    while (true)
    {
        if (SDL_PollEvent(&e))
        {
            if ((e.type == SDL_QUIT) | (e.type == SDL_KEYDOWN))
                break;
        }
    }

    // Destroy the window
    SDL_DestroyWindow(window);

    // Quit everything SDL created
    SDL_Quit();
    return 0;
}
