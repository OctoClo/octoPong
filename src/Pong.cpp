#include "Pong.h"

Pong::Pong():
    window(NULL),
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

    SDL_Renderer* windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!windowRenderer)
        fatalError("Error during render creation");

    playerL = new Player("Jesus");
    playerR = new Player("Buddha");

    gameBoard = new GameBoard(screenWidth, screenHeight, windowRenderer);
    gameBoard->init(playerL, playerR);

    //fontPath = "./resources/Dosis-Regular.otf";

    //fpsCounter = new FPSCounter(screenWidth / 4, 20, fontPath, 15, 255, 255, 255);
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
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            gameState = QUIT;

        else if ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.repeat == 0)
        {
            gameBoard->handleInput(event);
        }
    }
}

void Pong::update()
{
    enum BallOutOfScreen ballOutOfScreen = gameBoard->update();

    if (ballOutOfScreen != NOTOUT)
    {
        updateScores(ballOutOfScreen);
        gameBoard->init(playerL, playerR);
    }
}

void Pong::render()
{
    gameBoard->render();
    //fpsCounter->render(windowRenderer);
}

void Pong::updateScores(enum BallOutOfScreen ballOutOfScreen)
{
    if (ballOutOfScreen == LEFTOUT)
        playerR->increaseScore();
    else if (ballOutOfScreen == RIGHTOUT)
        playerL->increaseScore();
}

void Pong::cleanExit()
{
    SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}



