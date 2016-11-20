#include "../../include/game/GameManager.h"

GameManager::GameManager(SDL_Renderer* renderer)
{
    gameMainManager = GameMainManager::getInstance(renderer);
    gameMenuManager = GameMenuManager::getInstance(renderer);
}

GameManager::~GameManager()
{
    gameMainManager->killInstance();
    gameMainManager = NULL;
    gameMenuManager->killInstance();
    gameMenuManager = NULL;
}

void GameManager::launch()
{
    setStep(GAME_MAIN);
}

void GameManager::handleEvents(SDL_Event event)
{
    switch (step)
    {
    case GAME_MAIN:
        gameMainManager->handleEvents(event);
        break;

    case GAME_MENU:
        gameMenuManager->handleEvents(event);
        break;

    default:
        break;
    }
}

enum Step GameManager::update()
{
    enum Step returnStep;

    switch (step)
    {
    case GAME_MAIN:
        returnStep = gameMainManager->update();
        if (returnStep == GAME_MENU)
        {
            setStep(returnStep);
            cout << "Switched to GAME_MENU" << endl;
        }
        break;

    case GAME_MENU:
        returnStep = gameMenuManager->update();
        if (returnStep == GAME_MAIN)
        {
            setStep(returnStep);
            cout << "Switched to GAME_MENU" << endl;
        }
        break;

    default:
        break;
    }

    if (returnStep != QUIT && returnStep != MENU)
        returnStep = GAME;

    return returnStep;
}

void GameManager::render(SDL_Renderer* renderer)
{
    switch (step)
    {
    case GAME_MAIN:
        gameMainManager->render(renderer);
        break;

    case GAME_MENU:
        gameMenuManager->render(renderer);
        break;

    default:
        break;
    }
}

void GameManager::setStep(enum Step newStep)
{
    step = newStep;

    switch (step)
    {
    case GAME_MAIN:
        gameMainManager->launch();
        break;

    case GAME_MENU:
        gameMenuManager->launch();
        break;

    default:
        break;
    }
}

GameManager* GameManager::instance = NULL;

GameManager* GameManager::getInstance(SDL_Renderer* renderer)
{
    if (!instance)
        instance = new GameManager(renderer);

    return instance;
}

void GameManager::killInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}
