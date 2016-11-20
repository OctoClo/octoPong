#include "../../../include/menu/main/MenuMainManager.h"

MenuMainManager::MenuMainManager(SDL_Renderer* renderer)
{
    menu = new MenuMain(renderer);
}

void MenuMainManager::launch()
{
    menu->init();
}

void MenuMainManager::handleEvents(SDL_Event event)
{
    menu->handleEvents(event);
}

enum Step MenuMainManager::update()
{
    return menu->update();
}

void MenuMainManager::render(SDL_Renderer* renderer)
{
    menu->render(renderer);
}

MenuMainManager* MenuMainManager::instance = NULL;

MenuMainManager* MenuMainManager::getInstance(SDL_Renderer* renderer)
{
    if (!instance)
        instance = new MenuMainManager(renderer);

    return instance;
}

void MenuMainManager::killInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}


