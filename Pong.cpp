#include "Pong.h"

Pong::Pong()
{
    this->screenWidth = 500;
    this->screenHeight = 550;
    this->gameState = play;
}

Pong::~Pong()
{
}

void Pong::run()
{
    this->init();
    this->sprite.init(-1.0, -1.0, 1.0, 1.0);
    this->gameLoop();
    this->finish();
}

void Pong::init()
{
    // Initialize everything needed by SDL, catch the eventual error
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        fatalError("Error in SDL init");

    // Open the window
    this->window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->screenWidth, this->screenHeight, SDL_WINDOW_OPENGL);
    if (!window)
        fatalError("Error in window creation");

    // Create the OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext)
        fatalError("Error in OpenGL context creation");

    // Initiate glew
    glewExperimental = true;

    if (glewInit() != GLEW_OK)
        fatalError("Error in glew init");

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Activate the double buffer (1 window being cleared, 1 window being drawn)

    glClearColor(0.4, 0, 0.6, 1);
}

void Pong::gameLoop()
{
    // Process inputs while there is no exit
    while (this->gameState != quit)
    {
        this->processInput();
        this-> drawGame();
    }
}

void Pong::processInput()
{
    SDL_Event evnt;

    while (SDL_PollEvent(&evnt))
    {
        switch (evnt.type)
        {
            case SDL_QUIT:
                this->gameState = quit;
                break;

            case SDL_MOUSEMOTION:
                cout << evnt.motion.x << " ; " << evnt.motion.y << endl; // Display x and y coordinates
                break;

            case SDL_KEYDOWN:
                if (evnt.key.keysym.sym == SDLK_ESCAPE)
                    this->gameState = quit;
                break;

            default:
                break;
        }
    }
}

void Pong::drawGame()
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->sprite.draw();

    SDL_GL_SwapWindow(this->window);
}

void Pong::finish()
{
    // Destroy the window
    SDL_DestroyWindow(window);

    // Quit everything SDL created
    SDL_Quit();
}
