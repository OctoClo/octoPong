#include "Errors.h"

void fatalError(const string error, enum libraryError library)
{
    // Print error
    cerr << error << " : ";

	// Print details
	switch (library)
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
	}

    exit(EXIT_FAILURE);
}
