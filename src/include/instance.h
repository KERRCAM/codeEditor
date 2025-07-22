#ifndef INSTANCE_H
#define INSTANCE_H
#pragma once

// LIBRARY IMPORTS
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>
#include <tuple>

// LOCAL IMPORTS


//-----------------------------------------------------------------------------------------------//
// CLASS - FUNCTIONS + ATTRIBUTES

class Instance{

public:
    Instance();
    int initialiseWindow();
    void renderWindow();
    void destroyWindow();

private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int editorRunning1 = 0;
    int lastRendered = 0;

protected:


};

//-----------------------------------------------------------------------------------------------//

#endif
