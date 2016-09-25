#include "Pong.h"

Pong::Pong():
    screenWidth(400),
    screenHeight(300),
    gameState(PLAY),
    window(NULL),
    windowSurface(NULL),
    windowRenderer(NULL),
    ball(NULL)
{}

void Pong::run()
{
    init();
    gameLoop();
    cleanExit();
}

void Pong::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		fatalError("Error during SDL initialization");

	if (TTF_Init() != 0)
		fatalError("Error during SDL_ttf initialization", TTF);

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imageBitmask = IMG_Init(imageFlags);
	if ((imageBitmask & imageFlags) != imageFlags)
		fatalError("Error during SDL_image initialization", IMG);

	window = SDL_CreateWindow("OctoPong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (!window)
		fatalError("Error during window creation");

    windowSurface = SDL_GetWindowSurface(window);

    windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!windowRenderer)
        fatalError("Error during render creation");

    ball = new Ball(200, 150, 5);

    paddleL = new Paddle(10, 125, 10, 50);
    paddleR = new Paddle(380, 125, 10, 50);
}

void Pong::gameLoop()
{
    while (gameState != QUIT)
    {
        processInput();
         drawGame();
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
                gameState = QUIT;
                break;

            case SDL_MOUSEMOTION:
                //cout << evnt.motion.x << " ; " << evnt.motion.y << endl; // Display x and y coordinates
                break;

            case SDL_KEYDOWN:
                if (evnt.key.keysym.sym == SDLK_ESCAPE)
                    gameState = QUIT;
                break;

            default:
                break;
        }
    }
}

void Pong::drawGame()
{
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0x00, 0x00, 0x00 )); // Color screen in black

    ball->draw(windowRenderer);
    paddleL->draw(windowRenderer);
    paddleR->draw(windowRenderer);

    SDL_RenderPresent(windowRenderer);
}

void Pong::cleanExit()
{
    SDL_DestroyRenderer(windowRenderer);
    windowRenderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
