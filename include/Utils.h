#ifndef UTILS_H
#define UTILS_H

enum Direction { LEFT, RIGHT, TOP, BOTTOM, HORIZONTAL, VERTICAL, NONE };

enum Step { MENU, MENU_MAIN, GAME, GAME_MAIN, GAME_MENU, QUIT };

class Utils
{
    public :
        static const int SCREEN_WIDTH = 400;
        static const int SCREEN_HEIGHT = 300;
};

#endif // UTILS_H
