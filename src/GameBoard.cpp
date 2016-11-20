#include "GameBoard.h"

GameBoard::GameBoard(int newScreenWidth, int newScreenHeight, SDL_Renderer* newRenderer):
    screenWidth(newScreenWidth),
    screenHeight(newScreenHeight),
    gameBoardHeight(screenHeight - PLAYER_TEXT_WIDTH)
{
    renderer = newRenderer;

    ball = new Ball(renderer);
    paddleL = new Paddle(renderer);
    paddleR = new Paddle(renderer);
}

GameBoard::~GameBoard()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
}

void GameBoard::init(Player* newPlayerL, Player* newPlayerR)
{
    playerL = newPlayerL;
    playerR = newPlayerR;

    ball->init((screenWidth / 2) - ball->getRadius(), (screenHeight / 2)  - ball->getRadius());
    ballOutOfScreen = NONE;

    paddleL->init(10, 125);
    paddleR->init(380, 125);
}

void GameBoard::handleInput(SDL_Event event)
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

enum Direction GameBoard::update()
{
    ball->update();
    bounceBall();
    checkBallOutOfScreen(HORIZONTAL);

    paddleL->update();
    checkPaddleOutOfScreen(paddleL);

    paddleR->update();
    checkPaddleOutOfScreen(paddleR);

    playerL->update();
    playerR->update();

    return ballOutOfScreen;
}

void GameBoard::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);

    ball->render(renderer);
    paddleL->render(renderer);
    paddleR->render(renderer);
    playerL->render(2, renderer);
    playerR->render(screenWidth - playerR->getTextWidth() - 2, renderer);

    drawLines();

    SDL_RenderPresent(renderer);
}

void GameBoard::bounceBall()
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

bool GameBoard::checkPaddleCollision(enum Direction direction)
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
        fatalError("Direction inattendue dans la fonction checkPaddleCollision()");
        break;
    }

    return collision;
}

bool GameBoard::checkBallOutOfScreen(enum Direction direction)
{
    bool ballOut = 0;

    int ballX = ball->getX();
    int ballY = ball->getY();

    switch (direction)
    {
    case VERTICAL:
        ballOut = ballY + ball->getDiameter() >= screenHeight || ballY <= PLAYER_TEXT_WIDTH;
        break;

    case HORIZONTAL:
        if (ballX > screenWidth)
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
        fatalError("Direction inattendue dans la fonction checkBallOutOfScreen()");
        break;
    }

    return ballOut;
}

void GameBoard::checkPaddleOutOfScreen(Paddle* paddle)
{
    if (paddle->getY() <= PLAYER_TEXT_WIDTH + 1)
        paddle->decelerate();
    else if (paddle->getY() >= screenHeight - paddle->getHeight() - 1)
        paddle->decelerate();
}

void GameBoard::drawLines()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_RenderDrawLine(renderer, 0, PLAYER_TEXT_WIDTH, screenWidth, PLAYER_TEXT_WIDTH);
    SDL_RenderDrawLine(renderer, screenWidth / 2, PLAYER_TEXT_WIDTH, screenWidth / 2, screenHeight);
}

