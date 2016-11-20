#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../../include/game/main/GameMainManager.h"
#include "../../include/game/menu/GameMenuManager.h"

#include <SDL/SDL.h>

enum GameStep { GAME_MAIN, GAME_MENU };

class GameManager
{
    public:
        static GameManager* getInstance();
        static void killInstance();

        void setStep(enum GameStep);

        void launch();
        void handleEvents(SDL_Event);
        int update();
        void render(SDL_Renderer*);

    private:
        GameManager();
        ~GameManager();

        static GameManager* instance;

        enum GameStep step;

        GameMainManager* gameMainManager;
        GameMenuManager* gameMenuManager;
};

#endif // GAMEMANAGER_H
