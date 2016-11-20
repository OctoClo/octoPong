#include "../../../include/game/menu/GameMenuManager.h"

GameMenuManager::GameMenuManager(SDL_Renderer* renderer)
{
    menu = new GameMenu(renderer);
}

void GameMenuManager::launch()
{
    menu->init();
}

void GameMenuManager::handleEvents(SDL_Event event)
{
    menu->handleEvents(event);
}

enum Step GameMenuManager::update()
{
    return menu->update();
}

void GameMenuManager::render(SDL_Renderer* renderer)
{
    menu->render(renderer);
}

GameMenuManager* GameMenuManager::instance = NULL;

GameMenuManager* GameMenuManager::getInstance(SDL_Renderer* renderer)
{
    if (!instance)
        instance = new GameMenuManager(renderer);

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
