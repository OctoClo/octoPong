#include "../../../include/menu/main/MenuMainManager.h"

MenuMainManager* MenuMainManager::instance = NULL;

MenuMainManager* MenuMainManager::getInstance()
{
    if (!instance)
        instance = new MenuMainManager();

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

MenuMainManager::MenuMainManager()
{
    menu = new MenuMain();
}

void MenuMainManager::launch()
{
    menu->init();
}

void MenuMainManager::handleEvents(SDL_Event event)
{
    menu->handleEvents(event);
}

int MenuMainManager::update()
{
    return menu->update();
}

void MenuMainManager::render(SDL_Renderer* renderer)
{
    menu->render(renderer);
}


