#include "../../include/menu/MenuManager.h"

MenuManager::MenuManager(SDL_Renderer* renderer)
{
    menuMainManager = MenuMainManager::getInstance(renderer);
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

    default:
        break;
    }
}

enum Step MenuManager::update()
{
    Step returnStep;

    switch (step)
    {
    case MENU_MAIN:
        returnStep = menuMainManager->update();
        if (returnStep == MENU_MAIN)
            returnStep = MENU; // Si d'autres états, cf GameManager
        break;

    default:
        break;
    }

    return returnStep;
}

void MenuManager::render(SDL_Renderer* renderer)
{
    switch (step)
    {
    case MENU_MAIN:
        menuMainManager->render(renderer);
        break;

    default:
        break;
    }
}

void MenuManager::setStep(enum Step newStep)
{
    step = newStep;

    switch (step)
    {
    case MENU_MAIN:
        menuMainManager->launch();
        break;

    default:
        break;
    }
}

MenuManager* MenuManager::instance = NULL;

MenuManager* MenuManager::getInstance(SDL_Renderer* renderer)
{
    if (!instance)
        instance = new MenuManager(renderer);

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

