// LIBRARY IMPORTS
#include <SDL2/SDL.h>
#include <iostream>

// LOCAL IMPORTS
#include "include/instance.h"

//-----------------------------------------------------------------------------------------------//

int Instance::initialiseWindow(void){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Error initialising SDL\n");
        return 0;
    }

    window = SDL_CreateWindow(
        name.data(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS
    );

    if (!window){
        fprintf(stderr, "Error creating SDL window\n");
        return 0;
    }

    // -1 for default driver, 0 for no flags
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer){
        fprintf(stderr, "Error creating SDL renderer\n");
        return 0;
    }

    return 1;

}

//-----------------------------------------------------------------------------------------------//

void Instance::processInput(){

    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type){
    case SDL_QUIT:
        running = 0;
        break;
    case SDL_KEYDOWN:
        eventBuffer.push_back(event);
        std::cout << "scancode: " << event.key.keysym.scancode << std::endl;
        //std::cout << "sym: " << event.key.keysym.sym << std::endl;
        //std::cout << "mod: " << event.key.keysym.mod << std::endl;
        //std::cout << std::endl;
        if (event.key.keysym.sym == SDLK_ESCAPE){
            running = 0;
        }
        break;
    }

}

//-----------------------------------------------------------------------------------------------//

void Instance::render(){

    //WIP

}

//-----------------------------------------------------------------------------------------------//

void Instance::destroyWindow(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

//-----------------------------------------------------------------------------------------------//
