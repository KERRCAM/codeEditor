// LIBRARY IMPORTS
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

// LOCAL IMPORTS
#include "include/globals.h"
#include "include/manager.h"
#include "include/instance.h"
#include "include/keyMaps.h"

//-----------------------------------------------------------------------------------------------//

int main(){

    // copy code in below main into instance / manager classes

    return 0;
}

//-----------------------------------------------------------------------------------------------//



//-----------------------------------------------------------------------------------------------//
// INITIALISATIONS

std::vector<SDL_Event> eventBuffer;

SDL_Window* window1 = NULL;
SDL_Renderer* renderer1 = NULL;
SDL_Window* window2 = NULL;
SDL_Renderer* renderer2 = NULL;

int editorRunning1 = 0;
int editorRunning2 = 0;
int lastFrame = 0;

//-----------------------------------------------------------------------------------------------//

int initialize_window(SDL_Window* windowPH, SDL_Renderer* rendererPH){
    /*
    Sets up code winodw.
    */

    windowPH = SDL_CreateWindow(
        "TEST BUILD",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    if (!windowPH){
        fprintf(stderr, "Error creating SDL window\n");
        return 0;
    }

    // -1 for default driver, 0 for no flags
    rendererPH = SDL_CreateRenderer(windowPH, -1, 0);
    if (!rendererPH){
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
        editorRunning1 = 0;
        break;
    case SDL_KEYDOWN:
        eventBuffer.push_back(event);
        std::cout << std::endl;

        for (const auto& event : eventBuffer){
            std::cout << ", " << event.key.keysym.scancode;
        }

        std::cout << std::endl;

        if (event.key.keysym.sym == SDLK_ESCAPE){
            editorRunning1 = 0;
        }
        break;
    }

}

//-----------------------------------------------------------------------------------------------//

void setup(){
    /*
    Sets up so global values for the game and initialises various game aspects.
     */

}

//-----------------------------------------------------------------------------------------------//

void update(){
    /*
    Handles all required game updates ran each frame.
    */

    /* // ONLY NEEDED FOR A CAPPED FRAME RATE
    int waitTime = FRAME_TIME - (SDL_GetTicks() / lastFrame);
    if (waitTime > 0 && waitTime < FRAME_TIME){ SDL_Delay(waitTime); }
    */

}

//-----------------------------------------------------------------------------------------------//

void render(SDL_Renderer* rendererPH){
    /*
    Handle all render calls for the game.
    */

    // Screen colour
    SDL_SetRenderDrawColor(rendererPH, 0, 0, 60, 255);
    SDL_RenderClear(rendererPH);


    for (const auto& event : eventBuffer){
        int x = event.key.keysym.scancode;
        SDL_Rect squareRect = { x * 30, x * 30, 30, 30 };
        SDL_SetRenderDrawColor(rendererPH, x, x * 2 % 255, x * 3 % 255, 255);
        SDL_RenderFillRect(rendererPH, &squareRect);
    }

    SDL_RenderPresent(rendererPH);

}

//-----------------------------------------------------------------------------------------------//

void destroyWindow(){
    /*
    Destorys game renderer and window.
    */

    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window1);
    SDL_Quit();

}

//-----------------------------------------------------------------------------------------------//

//int main(){
//    /*
//    Main loop.
//    */
//
//    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
//        fprintf(stderr, "Error initialising SDL\n");
//        return 0;
//    }
//
//    editorRunning1 = initialize_window(window1, renderer1);
//    editorRunning2 = initialize_window(window2, renderer2);
//
//    setup();
//
//    while (editorRunning1){
//        processInput();
//        update();
//        render(renderer1);
//        render(renderer2);
//    }
//
//    destroyWindow();
//
//    return 0;
//
//}

//-----------------------------------------------------------------------------------------------//
