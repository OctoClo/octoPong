#include "MainManager.h"

MainManager* MainManager::instance = NULL;

MainManager* MainManager::getInstance()
{
    if (!instance)
        instance = new MainManager();

    return instance;
}

void MainManager::killInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}

MainManager::MainManager():
    renderer(NULL)
{
    initSDLSystems();

    menuManager = MenuManager::getInstance();
    gameManager = GameManager::getInstance();

    setStep(MENU);
}

MainManager::~MainManager()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
	window = NULL;

    menuManager->killInstance();
    menuManager = NULL;
    gameManager->killInstance();
    gameManager = NULL;

    IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void MainManager::handleEvents(SDL_Event event)
{
    if (event.type == SDL_QUIT)
        setStep(QUIT);
    else
    {
        switch (step)
        {
        case MENU:
            menuManager->handleEvents(event);
            break;

        case GAME:
            gameManager->handleEvents(event);
            break;

        case QUIT:
            break;
        }
    }
}

void MainManager::update()
{
    int returnValue;

    switch (step)
    {
    case MENU:
        returnValue = menuManager->update();
        break;

    case GAME:
        returnValue = gameManager->update();
        break;

    case QUIT:
        break;
    }

    if (!returnValue)
        setStep(QUIT);
}

void MainManager::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);

    switch (step)
    {
    case MENU:
        menuManager->render(renderer);
        break;

    case GAME:
        gameManager->render(renderer);
        break;

    case QUIT:
        break;
    }

    SDL_RenderPresent(renderer);
}

void MainManager::setStep(enum MainStep newStep)
{
    step = newStep;

    switch (step)
    {
    case MENU:
        menuManager->launch();
        break;

    case GAME:
        gameManager->launch();
        break;

    case QUIT:
        break;
    }
}

enum MainStep MainManager::getStep()
{
    return step;
}

void MainManager::initSDLSystems()
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

	window = SDL_CreateWindow("OctoPong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Utils::SCREEN_WIDTH, Utils::SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (!window)
		fatalError("Error during window creation");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
        fatalError("Error during render creation");
}
