#include "../../include/game/GameManager.h"

GameManager* GameManager::instance = NULL;

GameManager* GameManager::getInstance()
{
    if (!instance)
        instance = new GameManager();

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

GameManager::GameManager()
{
    gameMainManager = GameMainManager::getInstance();
    gameMenuManager = GameMenuManager::getInstance();
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
    }
}

int GameManager::update()
{
    int returnValue;

    switch (step)
    {
    case GAME_MAIN:
        returnValue = gameMainManager->update();
        break;

    case GAME_MENU:
        returnValue = gameMenuManager->update();
        break;
    }

    return returnValue;
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
    }
}

void GameManager::setStep(enum GameStep newStep)
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
    }
}

