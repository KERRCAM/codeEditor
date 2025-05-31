// LIBRARY IMPORTS
#include <SDL2/SDL.h>
#include <iostream>

// LOCAL IMPORTS
#include "include/input.h"
//#include "include/keyMaps.h"

//-----------------------------------------------------------------------------------------------//

void Input::getInput(SDL_Event event){

    if (event.type == SDL_KEYDOWN){
        eventBuffer.push_back(event);
    }

}

//-----------------------------------------------------------------------------------------------//
