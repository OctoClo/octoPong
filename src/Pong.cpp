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

Pong::~Pong()
{
}

void Pong::run()
{
    this->init();
    this->gameLoop();
    this->cleanExit();
}

void Pong::init()
{
    // Initialize SDL (video)
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		fatalError("Error during SDL initialization");

	// Initialize SDL_ttf
	if (TTF_Init() != 0)
		fatalError("Error during SDL_ttf initialization", TTF);

	// Initialize SDL_image (JPG and PNG support)
	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imageBitmask = IMG_Init(imageFlags);
	if ((imageBitmask & imageFlags) != imageFlags)
		fatalError("Error during SDL_image initialization", IMG);

	// Initialize SDL_mixer (MP3 support)
	int mixerFlags = MIX_INIT_MP3;
	int mixerBitmask = Mix_Init(mixerFlags);
	if ((mixerBitmask & mixerFlags) != mixerFlags)
		fatalError("Error during SDL_mixer initialization", MIX);

	// Initialize SDL_net
	if (SDLNet_Init() != 0)
		fatalError("Error during SDL_net initialization", NET);

	// Open window
	this->window = SDL_CreateWindow("OctoPong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->screenWidth, this->screenHeight, SDL_WINDOW_OPENGL);
	if (!this->window)
		fatalError("Error during window creation");

    // Link surface to window
    this->windowSurface = SDL_GetWindowSurface(this->window);

    // Create renderer for window
    this->windowRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->windowRenderer)
        fatalError("Error during render creation");

    // Initialize ball
    this->ball = new Ball();
    this->ball->init(200, 150, 10);
}

void Pong::gameLoop()
{
    // Process inputs while there is no exit
    while (this->gameState != QUIT)
    {
        this->processInput();
        this-> drawGame();
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
                this->gameState = QUIT;
                break;

            case SDL_MOUSEMOTION:
                cout << evnt.motion.x << " ; " << evnt.motion.y << endl; // Display x and y coordinates
                break;

            case SDL_KEYDOWN:
                if (evnt.key.keysym.sym == SDLK_ESCAPE)
                    this->gameState = QUIT;
                break;

            default:
                break;
        }
    }
}

void Pong::drawGame()
{
    // Color screen in black
    SDL_FillRect(this->windowSurface, NULL, SDL_MapRGB(this->windowSurface->format, 0x00, 0x00, 0x00 ));

    // Draw ball
    ball->draw(this->windowRenderer);

    // Udpate screen
    SDL_RenderPresent(this->windowRenderer);
    // SDL_UpdateWindowSurface(this->window);
}

void Pong::cleanExit()
{
    // Destroy renderer
    SDL_DestroyRenderer(this->windowRenderer);
    this->windowRenderer = NULL;

    // Destroy window
	SDL_DestroyWindow(this->window);
	this->window = NULL;

	// Quit every SDL subsystem and SDL
	SDLNet_Quit();
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
