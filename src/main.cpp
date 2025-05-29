// LIBRARY IMPORTS
#include <iostream>
#include <SDL2/SDL.h>

// LOCAL IMPORTS
#include "include/globals.h"
#include "include/manager.h"
#include "include/input.h"
#include "include/keyMaps.h"

//-----------------------------------------------------------------------------------------------//


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//-----------------------------------------------------------------------------------------------//

int initialize_window(void){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Error initialising SDL\n");
        return 0;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
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

void processInput(){

    SDL_Event event;
    SDL_PollEvent(&event);



    switch (event.type){
        case SDL_QUIT:
            running = 0;
            break;
        case SDL_KEYDOWN:
            //std::cout << "scancode: " << event.key.keysym.scancode << std::endl;
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

void destroyWindow(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

//-----------------------------------------------------------------------------------------------//

int main(){



    running = initialize_window();



    while (running){
        processInput();

    }

    destroyWindow();

    return 0;
}