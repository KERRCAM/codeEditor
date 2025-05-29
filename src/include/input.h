#ifndef INPUT_H
#define INPUT_H
#pragma once

// LIBRARY IMPORTS
#include <SDL2/SDL.h>
#include <vector>

// LOCAL IMPORTS


//-----------------------------------------------------------------------------------------------//
// CLASS - FUNCTIONS + ATTRIBUTES

class Input{

public:
    void getInput(SDL_Event event);

private:
    std::vector<SDL_Event> eventBuffer;

    //void getInput(SDL_Event event);

protected:


};

//-----------------------------------------------------------------------------------------------//

#endif
