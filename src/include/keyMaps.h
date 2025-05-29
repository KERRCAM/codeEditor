#ifndef KEYMAPS_H
#define KEYMAPS_H
#pragma once

// LIBRARY IMPORTS
#include <SDL2/SDL.h>
#include <map>

// LOCAL IMPORTS


//-----------------------------------------------------------------------------------------------//

std::map<SDL_Event, char> keyMaps = {
    {SDLD_a, 'a'},
    {SDLK_b, 'b'},
};

//-----------------------------------------------------------------------------------------------//

#endif