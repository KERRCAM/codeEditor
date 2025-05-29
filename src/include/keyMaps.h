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
    {SDLD_c, 'c'},
    {SDLK_d, 'd'},
    {SDLD_e, 'e'},
    {SDLK_f, 'f'},
    {SDLD_g, 'g'},
    {SDLK_h, 'h'},
    {SDLD_i, 'i'},
    {SDLK_j, 'j'},
    {SDLD_k, 'k'},
    {SDLK_l, 'l'},
    {SDLD_m, 'm'},
    {SDLK_n, 'n'},
    {SDLD_o, 'o'},
    {SDLK_p, 'p'},
    {SDLD_q, 'q'},
    {SDLK_r, 'r'},
    {SDLD_s, 's'},
    {SDLK_t, 't'},
    {SDLD_u, 'u'},
    {SDLK_v, 'v'},
    {SDLD_w, 'w'},
    {SDLK_x, 'x'},
    {SDLD_y, 'y'},
    {SDLK_z, 'z'},
};

//-----------------------------------------------------------------------------------------------//

#endif