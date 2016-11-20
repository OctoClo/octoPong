#include "../../../include/game/main/GameMain.h"

GameMain::GameMain(SDL_Renderer* renderer):
    gameBoardHeight(Utils::SCREEN_HEIGHT - PLAYER_TEXT_WIDTH)
{
    ball = new Ball(renderer);
    paddleL = new Paddle(renderer);
    paddleR = new Paddle(renderer);
    playerL = new Player("Jesus");
    playerR = new Player("Buddha");
}

void GameMain::init()
{
    ball->init((Utils::SCREEN_WIDTH / 2) - ball->getRadius(), (Utils::SCREEN_HEIGHT / 2)  - ball->getRadius());
    ballOutOfScreen = NONE;

    paddleL->init(10, 125);
    paddleR->init(380, 125);
}

void GameMain::reset()
{
    playerL->reset();
    playerR->reset();
}

void GameMain::handleEvents(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_z:
            paddleL->accelerate(TOP);
            break;

        case SDLK_s:
            paddleL->accelerate(BOTTOM);
            break;

        case SDLK_UP:
            paddleR->accelerate(TOP);
            break;

        case SDLK_DOWN:
            paddleR->accelerate(BOTTOM);
            break;
        }
    }

    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_z:
        case SDLK_s:
            paddleL->decelerate();
            break;

        case SDLK_UP:
        case SDLK_DOWN:
            paddleR->decelerate();
            break;
        }
    }
}

enum Step GameMain::update()
{
    enum Step returnStep = GAME_MAIN;

    ball->update();
    bounceBall();
    if (checkBallOutOfScreen(HORIZONTAL))
        returnStep = checkScores();

    paddleL->update();
    checkPaddleOutOfScreen(paddleL);

    paddleR->update();
    checkPaddleOutOfScreen(paddleR);

    playerL->update();
    playerR->update();

    return returnStep;
}

void GameMain::render(SDL_Renderer* renderer)
{
    ball->render(renderer);

    paddleL->render(renderer);
    paddleR->render(renderer);

    playerL->render(2, renderer);
    playerR->render(Utils::SCREEN_WIDTH - playerR->getTextWidth() - 2, renderer);

    drawLines(renderer);
}

void GameMain::bounceBall()
{
    // Bouncing on top & bottom of the screen
    if (checkBallOutOfScreen(VERTICAL))
        ball->invertSpeedY();

    // Bouncing on the left paddle
    if (checkPaddleCollision(LEFT))
        ball->invertSpeedX();

    // Bouncing on the right paddle
    if (checkPaddleCollision(RIGHT))
        ball->invertSpeedX();
}

bool GameMain::checkPaddleCollision(enum Direction direction)
{
    bool collision;

    int ballX = ball->getX();
    int ballY = ball->getY();
    int ballDiameter = ball->getDiameter();

    int paddleX;
    int paddleY;
    int paddleHeight;
    int paddleWidth;

    switch (direction)
    {
    case LEFT:
        paddleX = paddleL->getX();
        paddleY = paddleL->getY();
        paddleHeight = paddleL->getHeight();
        paddleWidth = paddleL->getWidth();

        collision =     ballX <= paddleX + paddleWidth // Checking right x axis
                            &&
                        ballX + ballDiameter >= paddleX // Checking left x axis
                            &&
                        ballY >= paddleY // Checking top y axis
                            &&
                        ballY + ballDiameter <= paddleY + paddleHeight; // Checking bottom y axis
        break;

    case RIGHT:
        paddleX = paddleR->getX();
        paddleY = paddleR->getY();
        paddleHeight = paddleR->getHeight();
        paddleWidth = paddleR->getWidth();

        collision =     ballX + ballDiameter >= paddleX // Checking right x axis
                            &&
                        ballX <= paddleX + paddleWidth
                            &&
                        ballY >= paddleY // Checking top y axis
                            &&
                        ballY + ballDiameter <= paddleY + paddleHeight; // Checking bottom y axis
        break;

    default:
        //fatalError("Direction inattendue dans la fonction checkPaddleCollision()");
        break;
    }

    return collision;
}

bool GameMain::checkBallOutOfScreen(enum Direction direction)
{
    bool ballOut = 0;

    int ballX = ball->getX();
    int ballY = ball->getY();

    switch (direction)
    {
    case VERTICAL:
        ballOut = ballY + ball->getDiameter() >= Utils::SCREEN_HEIGHT || ballY <= PLAYER_TEXT_WIDTH;
        break;

    case HORIZONTAL:
        if (ballX > Utils::SCREEN_WIDTH)
        {
            ballOut = 1;
            ballOutOfScreen = RIGHT;
        }
        else if (ballX + ball->getDiameter() < 0)
        {
            ballOut = 1;
            ballOutOfScreen = LEFT;
        }
        break;

    default:
        //fatalError("Direction inattendue dans la fonction checkBallOutOfScreen()");
        break;
    }

    return ballOut;
}

void GameMain::checkPaddleOutOfScreen(Paddle* paddle)
{
    if (paddle->getY() <= PLAYER_TEXT_WIDTH + 2)
    {
        paddle->goDown();
        paddle->decelerate();
    }
    else if (paddle->getY() >= Utils::SCREEN_HEIGHT - paddle->getHeight() - 2)
    {
        paddle->goUp();
        paddle->decelerate();
    }
}

enum Step GameMain::checkScores()
{
    enum Step returnStep = GAME_MAIN;

    updateScores();

    if (playerL->getScore() >= 3 || playerR->getScore() >= 3)
    {
        if (playerL->getScore() >= 3) // todo: faire un écran de félicitations
            cout << playerL->getName() << " won !" << endl;
        else
            cout << playerR->getName() << " won !" << endl;

        reset();
        returnStep = MENU;
    }
    else
        init();

    return returnStep;
}

void GameMain::updateScores()
{
    switch (ballOutOfScreen)
    {
    case LEFT:
        playerR->increaseScore();
        break;

    case RIGHT:
        playerL->increaseScore();
        break;

    default:
        //fatalError("Direction inattendue dans la fonction updateScores()");
        break;
    }
}

void GameMain::drawLines(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_RenderDrawLine(renderer, 0, PLAYER_TEXT_WIDTH, Utils::SCREEN_WIDTH, PLAYER_TEXT_WIDTH);
    SDL_RenderDrawLine(renderer, Utils::SCREEN_WIDTH / 2, PLAYER_TEXT_WIDTH, Utils::SCREEN_WIDTH / 2, Utils::SCREEN_HEIGHT);
}
