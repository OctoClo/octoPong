#include "Pong.h"
#include "MainManager.h"

#include <iostream>
using namespace std;

int main (int argc, char** argv)
{
    /*Pong pong;
    pong.run();*/

    MainManager* manager = MainManager::getInstance();
    SDL_Event event;

    while (manager->getStep() != QUIT)
    {
        while (SDL_PollEvent(&event))
        {
            manager->handleEvents(event);
        }
        manager->update();
        manager->render();
    }

    manager->killInstance();

    return EXIT_SUCCESS;
}
