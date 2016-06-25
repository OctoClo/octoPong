#include "Errors.h"

void fatalError(string error)
{
    char key;

    // Print the error
    cout << error << " : " << SDL_GetError() << endl;

    // Wait for the user to enter a key
    cout << "Enter any key to leave" << endl;
    cin >> key;

    // Quit everything SDL created
    SDL_Quit();

    // exit(1);
}
