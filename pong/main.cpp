#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

int main (int argc, char** argv)
{
    // Initialize everything needed by SDL, catch the eventual error
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Error during SDL's initialization : " << SDL_GetError();
        return 1;
    }

    // Create a window
    SDL_Window* window;
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

    // Catch the eventual error
    if (window == NULL)
    {
        std::cout << "Error during window's creation : " << SDL_GetError();
        return 1;
    }

    // OpenGL context test
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    glClearColor(0,0,0,1);

    SDL_GL_DeleteContext(glContext);

    SDL_Delay(2000);

    // Destroy the window
    SDL_DestroyWindow(window);

    // Quit everything SDL created
    SDL_Quit();
    return 0;
}
