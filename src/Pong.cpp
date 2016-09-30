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
    updateScores();
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

    ball = new Ball(screenWidth, screenHeight, windowRenderer);

    playerL = new Player("Jesus", LEFTPOS, screenHeight);
    playerR = new Player("Buddha", RIGHTPOS, screenHeight);

    fontPath = "./resources/Dosis-Regular.otf";

    fpsCounter = new FPSCounter(screenWidth / 4, 20, fontPath, 15, 255, 255, 255);
}

void Pong::gameLoop()
{
    while (gameState != QUIT && !ball->isOffScreen())
    {
        processInput();
        update();
        render();
    }
}

void Pong::processInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            gameState = QUIT;

        else if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_z:
            case SDLK_s:
                playerL->handleInput(event);
                break;

            case SDLK_UP:
            case SDLK_DOWN:
                playerR->handleInput(event);
                break;
            }
        }
    }
}

void Pong::update()
{
    playerL->update();
    playerR->update();
    ball->update(playerL->getPaddle(), playerR->getPaddle());
    fpsCounter->update();
}

void Pong::render()
{
    SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(windowRenderer);

    ball->render(windowRenderer);
    playerL->render(windowRenderer);
    playerR->render(windowRenderer);
    fpsCounter->render(windowRenderer);

    SDL_RenderPresent(windowRenderer);
}

void Pong::updateScores()
{
    if (ball->getSideOut() == LEFTOUT)
        playerR->increaseScore();
    else if (ball->getSideOut() == RIGHTOUT)
        playerL->increaseScore();
    gameLoop();
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



