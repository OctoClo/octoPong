#include "Menu.h"

enum Step Menu::update()
{
    for (auto& component : components)
    	component->update();

    return QUIT;
}

void Menu::render(SDL_Renderer* renderer)
{
    for (auto& component : components)
    	component->render(renderer);
}
