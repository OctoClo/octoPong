#include "../../../include/game/main/GameMainManager.h"

GameMainManager* GameMainManager::instance = NULL;

GameMainManager* GameMainManager::getInstance()
{
    if (!instance)
        instance = new GameMainManager();

    return instance;
}

void GameMainManager::killInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}

GameMainManager::GameMainManager()
{
    game = new GameMain();
}

void GameMainManager::launch()
{
    game->init();
}

void GameMainManager::handleEvents(SDL_Event event)
{
    game->handleEvents(event);
}

int GameMainManager::update()
{
    return game->update();
}

void GameMainManager::render(SDL_Renderer* renderer)
{
    game->render(renderer);
}


