#include "GameBoard.h"

GameBoard::GameBoard(int newScreenWidth, int newScreenHeight, SDL_Renderer* renderer):
    screenWidth(newScreenWidth),
    screenHeight(newScreenHeight)
{
    this->renderer = renderer;

    ball = new Ball(renderer);
    paddleL = new Paddle(10, 50);
    paddleR = new Paddle(10, 50);
}

GameBoard::~GameBoard()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
}

void GameBoard::init()
{
    ball->init(screenWidth / 2, screenWidth / 2);
    ballOutOfScreen = NOTOUT;

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
                paddleL->accelerate(UPDIR);
                break;

            case SDLK_s:
                paddleL->accelerate(DOWNDIR);
                break;

            case SDLK_UP:
                paddleR->accelerate(UPDIR);
                break;

            case SDLK_DOWN:
                paddleR->accelerate(DOWNDIR);
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

enum BallOutOfScreen GameBoard::update()
{
    ball->update();
    bounceBall();
    checkBallOutOfScreen();

    paddleL->update();
    checkPaddleOutOfScreen(paddleL);

    paddleR->update();
    checkPaddleOutOfScreen(paddleR);

    return ballOutOfScreen;
}

void GameBoard::bounceBall()
{
    int ballX = ball->getX();
    int ballY = ball->getY();
    int ballRadius = ball->getRadius();

    // Bouncing on top & bottom of the screen
    if (ballY + ballRadius >= screenHeight || ballY <= ballRadius)
        ball->invertSpeedY();

    int paddleX = paddleL->getX();
    int paddleY = paddleL->getY();

    // Bouncing on the left paddle
    if (ballX - ballRadius <= paddleX + paddleL->getWidth() // Checking x axis
            &&
        ballY - ballRadius <= paddleY + paddleL->getHeight() // Checking bottom y axis
            &&
        ballY + ballRadius >= paddleY) // Checking top y axis
        ball->invertSpeedX();

    paddleX = paddleR->getX();
    paddleY = paddleR->getY();

    // Bouncing on the right paddle
    if (ballX + ballRadius >= paddleX // Checking x axis
            &&
        ballY - ballRadius <= paddleY + paddleR->getHeight() // Checking bottom y axis
            &&
        ballY + ballRadius >= paddleY) // Checking top y axis
        ball->invertSpeedX();
}

void GameBoard::checkBallOutOfScreen()
{
    if (ball->getX() - ball->getRadius() > screenWidth)
        ballOutOfScreen = RIGHTOUT;
    else if (ball->getX() + ball->getRadius() < 0)
        ballOutOfScreen = LEFTOUT;
}

void GameBoard::checkPaddleOutOfScreen(Paddle* paddle)
{
    if (paddle->getY() <= 1)
        paddle->moove(DOWNDIR);
    else if (paddle->getY() >= screenHeight - paddle->getHeight() - 1)
        paddle->moove(UPDIR);
}

void GameBoard::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);

    ball->render(renderer);
    paddleL->render(renderer);
    paddleR->render(renderer);

    SDL_RenderPresent(renderer);
}
