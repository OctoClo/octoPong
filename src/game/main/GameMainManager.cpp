#include "../../../include/game/main/GameMainManager.h"

GameMainManager::GameMainManager(SDL_Renderer* renderer)
{
    game = new GameMain(renderer);
}

void GameMainManager::launch()
{
    game->init();
}

void GameMainManager::handleEvents(SDL_Event event)
{
    game->handleEvents(event);
}

enum Step GameMainManager::update()
{
    return game->update();
}

void GameMainManager::render(SDL_Renderer* renderer)
{
    game->render(renderer);
}

GameMainManager* GameMainManager::instance = NULL;

GameMainManager* GameMainManager::getInstance(SDL_Renderer* renderer)
{
    if (!instance)
        instance = new GameMainManager(renderer);

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

