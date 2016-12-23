#include "../../../include/menu/main/MenuMain.h"

MenuMain::MenuMain(SDL_Renderer* renderer)
{
	components.push_back(new GameComponent(renderer, "./resources/ButtonPlay.png"));
    components.push_back(new GameComponent(renderer, "./resources/ButtonQuit.png"));

    buttonSelection = new GameComponent(renderer, "./resources/ButtonSelection.png");
}

void MenuMain::init()
{
    selection = 0;
    launched = -1;

    int currentX = (Utils::SCREEN_WIDTH / 2) - (components.at(0)->getWidth() / 2);
    int currentY = (Utils::SCREEN_HEIGHT / 2) - components.at(0)->getHeight();
    components.at(0)->init(currentX, currentY);

    currentX = (Utils::SCREEN_WIDTH / 2) - (components.at(1)->getWidth() / 2);
    currentY = components.at(0)->getY() + components.at(0)->getHeight() + 20;
    components.at(1)->init(currentX, currentY);

    updateButtonSelection();
}

void MenuMain::handleEvents(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_RETURN)
            launched = selection;
        else if (event.key.keysym.sym == SDLK_UP)
            selection = --selection % components.size();
        else if (event.key.keysym.sym == SDLK_DOWN)
            selection = ++selection % components.size();
    }
}

enum Step MenuMain::update()
{
    enum Step returnStep;

    updateButtonSelection();

    switch (launched)
    {
    case -1:
        returnStep = MENU_MAIN;
        break;

    case 0:
        returnStep = GAME;
        break;

    case 1:
        returnStep = QUIT;
        break;
    }

    Menu::update();

    return returnStep;
}

void MenuMain::render(SDL_Renderer* renderer)
{
    Menu::render(renderer);

    buttonSelection->render(renderer);
}

void MenuMain::updateButtonSelection()
{
    buttonSelection->setX(components.at(selection)->getX() - 10);
    buttonSelection->setY(components.at(selection)->getY());
}
