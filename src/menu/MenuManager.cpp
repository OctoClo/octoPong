#include "../../include/menu/MenuManager.h"

MenuManager* MenuManager::instance = NULL;

MenuManager* MenuManager::getInstance()
{
    if (!instance)
        instance = new MenuManager();

    return instance;
}

void MenuManager::killInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}

MenuManager::MenuManager()
{
    menuMainManager = MenuMainManager::getInstance();
}

MenuManager::~MenuManager()
{
    menuMainManager->killInstance();
    menuMainManager = NULL;
}

void MenuManager::launch()
{
    setStep(MENU_MAIN);
}

void MenuManager::handleEvents(SDL_Event event)
{
    switch (step)
    {
    case MENU_MAIN:
        menuMainManager->handleEvents(event);
        break;
    }
}

int MenuManager::update()
{
    int returnValue;

    switch (step)
    {
    case MENU_MAIN:
        returnValue = menuMainManager->update();
        break;
    }

    return returnValue;
}

void MenuManager::render(SDL_Renderer* renderer)
{
    switch (step)
    {
    case MENU_MAIN:
        menuMainManager->render(renderer);
        break;
    }
}

void MenuManager::setStep(enum MenuStep newStep)
{
    step = newStep;

    switch (step)
    {
    case MENU_MAIN:
        menuMainManager->launch();
        break;
    }
}

