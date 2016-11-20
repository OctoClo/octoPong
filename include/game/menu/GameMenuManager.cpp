#include "GameMenuManager.h"

GameMenuManager* GameMenuManager::instance = NULL;

GameMenuManager* GameMenuManager::getInstance()
{
    if (!instance)
        instance = new GameMenuManager();

    return instance;
}

void GameMenuManager::killInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}

GameMenuManager::GameMenuManager()
{
    menu = new GameMenu();
}

void GameMenuManager::launch()
{
    menu->init();
}

void GameMenuManager::handleEvents(SDL_Event* event)
{
    menu->handleEvents(event);
}

void GameMenuManager::update()
{
    menu->update();
}

void GameMenuManager::render(SDL_Renderer* renderer)
{
    menu->render(renderer);
}
