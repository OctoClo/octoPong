#include "Pong.h"

Pong::Pong():
    screenWidth(400),
    screenHeight(300),
    gameState(PLAY),
    window(NULL),
    windowSurface(NULL),
    windowRenderer(NULL),
    ball(NULL)
{}

void Pong::run()
{
    init();
    gameLoop();
    cleanExit();
}

void Pong::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		fatalError("Error during SDL initialization");

	if (TTF_Init() != 0)
		fatalError("Error during SDL_ttf initialization", TTF);

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imageBitmask = IMG_Init(imageFlags);
	if ((imageBitmask & imageFlags) != imageFlags)
		fatalError("Error during SDL_image initialization", IMG);

	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        fatalError("Warning : Linear texture filtering not enabled !");

	window = SDL_CreateWindow("OctoPong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (!window)
		fatalError("Error during window creation");

    windowSurface = SDL_GetWindowSurface(window);

    windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!windowRenderer)
        fatalError("Error during render creation");

    if (!loadMedia())
        fatalError("Error during font loading", TTF);

    textColor = new SDL_Color();
    textColor->r = 255;
    textColor->g = 255;
    textColor->b = 255;
    textColor->a = 255;

    countedFrames = 0;

    ball = new Ball(screenWidth / 2, screenHeight / 2, 5);

    paddleL = new Paddle(10, 125, 10, 50);
    paddleR = new Paddle(380, 125, 10, 50);
}

void Pong::gameLoop()
{
    while (gameState != QUIT)
    {
        processInput();
        calculateFPS();
        drawGame();
        countedFrames++;
    }
}

void Pong::processInput()
{
    SDL_Event evnt;

    while (SDL_PollEvent(&evnt))
    {
        switch (evnt.type)
        {
            case SDL_QUIT:
                gameState = QUIT;
                break;

            case SDL_MOUSEMOTION:
                //cout << evnt.motion.x << " ; " << evnt.motion.y << endl; // Display x and y coordinates
                break;

            case SDL_KEYDOWN:
                switch (evnt.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gameState = QUIT;
                    break;

                case SDLK_z:
                    paddleL->movePaddle(UP);
                    break;

                case SDLK_s:
                    paddleL->movePaddle(DOWN);
                    break;

                case SDLK_UP:
                    paddleR->movePaddle(UP);
                    break;

                case SDLK_DOWN:
                    paddleR->movePaddle(DOWN);
                    break;
                }
                break;

            default:
                break;
        }
    }
}

void Pong::drawGame()
{
    SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(windowRenderer);

    ball->draw(windowRenderer);
    paddleL->draw(windowRenderer);
    paddleR->draw(windowRenderer);
    renderFPS();

    SDL_RenderPresent(windowRenderer);
}

void Pong::cleanExit()
{
    FPSTexture.free();

    TTF_CloseFont(font);
    font = NULL;

    SDL_DestroyRenderer(windowRenderer);
    windowRenderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool Pong::loadMedia()
{
    bool success = true;

    font = TTF_OpenFont("D:/Font/Dosis-Regular.otf", 15);
    if (!font)
        success = false;

    return success;
}

void Pong::calculateFPS()
{
    float averageFPS = countedFrames / (SDL_GetTicks() / 1000.f);

    if (averageFPS > 2000000)
    {
        averageFPS = 0;
    }

    timeText.str("");
    timeText << "Average Frames Per Second " << round(averageFPS);
}

void Pong::renderFPS()
{
    if (!FPSTexture.loadFromRenderedText(timeText.str(), textColor, font, windowRenderer))
        fatalError("Unable to render FPS texture");

    FPSTexture.draw(screenWidth / 4, FPSTexture.getHeight(), windowRenderer);
}
