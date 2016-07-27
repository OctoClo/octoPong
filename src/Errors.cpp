#include "Errors.h"

void fatalError(const string error, enum librairyError librairy)
{
    // Print error
    cerr << error << " : ";

	// Print details
	switch (librairy)
	{
	case SDL:
		cerr << SDL_GetError();
		break;

	case TTF:
	    cerr << TTF_GetError();
		break;

	case IMG:
	    cerr << IMG_GetError();
		break;

	case MIX:
	    cerr << Mix_GetError();
		break;

	case NET:
	    cerr << SDLNet_GetError();
		break;
	}

    // Print the error
    cout << error << " : " << SDL_GetError() << endl;

    exit(EXIT_FAILURE);
}
