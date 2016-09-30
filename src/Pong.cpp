#include "Pong.h"

Pong::Pong():
    screenWidth(400),
    screenHeight(300),
    window(NULL),
    windowRenderer(NULL),
    gameState(PLAY)
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

	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        fatalError("Warning : Linear texture filtering not enabled !");

	window = SDL_CreateWindow("OctoPong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (!window)
		fatalError("Error during window creation");

    windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!windowRenderer)
        fatalError("Error during render creation");

    //if (!loadMedia())
    //    fatalError("", );

    ball = new Ball(screenWidth / 2, screenHeight / 2, windowRenderer);

    paddleL = new Paddle(10, 125, 10, 50);
    paddleR = new Paddle(380, 125, 10, 50);

    fontPath = "./resources/Dosis-Regular.otf";

    fpsCounter = new FPSCounter(screenWidth / 4, 20, fontPath, 15, 255, 255, 255);
}

void Pong::gameLoop()
{
    while (gameState != QUIT)
    {
        processInput();
        update();
        render();
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
                switch (evnt.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gameState = QUIT;
                    break;

                case SDLK_z:
                    paddleL->update(UP);
                    break;

                case SDLK_s:
                    paddleL->update(DOWN);
                    break;

                case SDLK_UP:
                    paddleR->update(UP);
                    break;

                case SDLK_DOWN:
                    paddleR->update(DOWN);
                    break;
                }
                break;

            default:
                break;
        }
    }
}

void Pong::update()
{
    fpsCounter->update();
}

void Pong::render()
{
    SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(windowRenderer);

    ball->render(windowRenderer);
    paddleL->render(windowRenderer);
    paddleR->render(windowRenderer);
    fpsCounter->render(windowRenderer);

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

bool Pong::loadMedia()
{
    return true;
}




