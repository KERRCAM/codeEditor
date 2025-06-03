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

    int x = 150;
    SDL_Rect squareRect = { x, x, 10, 10 };


    SDL_SetRenderDrawColor(renderer, x, x, x, 255);
    SDL_RenderFillRect(renderer, &squareRect);


    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type){
    case SDL_QUIT:
        running = 0;
        break;
    case SDL_KEYDOWN:
        eventBuffer.push_back(event);
        //std::cout << "scancode: " << event.key.keysym.scancode << std::endl;
        //std::cout << "sym: " << event.key.keysym.sym << std::endl;
        //std::cout << "mod: " << event.key.keysym.mod << std::endl;
        std::cout << std::endl;

        for (const auto& event : eventBuffer){
            std::cout << ", " << event.key.keysym.scancode;
        }

        std::cout << std::endl;

        if (event.key.keysym.sym == SDLK_ESCAPE){
            running = 0;
        }
        break;
    }



}

//-----------------------------------------------------------------------------------------------//

void Instance::render(){

    SDL_RenderClear(renderer);

    if (eventBuffer.size() > 0){
        SDL_Event event = eventBuffer.back();
        eventBuffer.pop_back();

        int x = event.key.keysym.scancode;

        SDL_SetRenderDrawColor(renderer, x, x, x, 255);
        SDL_RenderDrawPoint(renderer, x, x);

        SDL_Rect squareRect = { x, x, 10, 10 };

        SDL_SetRenderDrawColor(renderer, x, x, x, 255);
        SDL_RenderFillRect(renderer, &squareRect);

    }

    SDL_RenderPresent(renderer);


}

//-----------------------------------------------------------------------------------------------//

void Instance::destroyWindow(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

//-----------------------------------------------------------------------------------------------//
