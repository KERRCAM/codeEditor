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

//int main(){
//
//    Instance* i1 = new Instance("i1", 800, 500, 1);
//
//    Manager* manager = new Manager(); // TODO - need to setup multiple windows simultaneous inputs
//    manager -> addInstance();
//
//    int lastFrame = SDL_GetTicks();
//
//    while (i1 -> isRunning()){
////        if (SDL_GetTicks() - lastFrame > REFRESH_RATE){
////            i1 -> render();
////        }
//        SDL_RenderClear(i1 -> renderer);
//        i1 -> processInput();
//        SDL_RenderPresent(i1 -> renderer);
//
//
//    }
//
//    return 0;
//}

//-----------------------------------------------------------------------------------------------//



//-----------------------------------------------------------------------------------------------//
// INITIALISATIONS

std::vector<SDL_Event> eventBuffer;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int editorRunning = 0;
int lastFrame = 0;
int endScreen = 0;

//-----------------------------------------------------------------------------------------------//

int initialize_window(void){
    /*
    Sets up code winodw.
    */

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Error initialising SDL\n");
        return 0;
    }

    window = SDL_CreateWindow(
        "TEST BUILD",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE
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
        editorRunning = 0;
        break;
    case SDL_KEYDOWN:
        eventBuffer.push_back(event);
        std::cout << std::endl;

        for (const auto& event : eventBuffer){
            std::cout << ", " << event.key.keysym.scancode;
        }

        std::cout << std::endl;

        if (event.key.keysym.sym == SDLK_ESCAPE){
            editorRunning = 0;
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

void render(){
    /*
    Handle all render calls for the game.
    */

    // Screen colour
    SDL_SetRenderDrawColor(renderer, 0, 0, 60, 255);
    SDL_RenderClear(renderer);


    for (const auto& event : eventBuffer){
        int x = event.key.keysym.scancode;
        SDL_Rect squareRect = { x * 30, x * 30, 30, 30 };
        SDL_SetRenderDrawColor(renderer, x, x * 2 % 255, x * 3 % 255, 255);
        SDL_RenderFillRect(renderer, &squareRect);
    }

    SDL_RenderPresent(renderer);

}

//-----------------------------------------------------------------------------------------------//

void destroyWindow(){
    /*
    Destorys game renderer and window.
    */

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

//-----------------------------------------------------------------------------------------------//

int main(){
    /*
    Main loop.
    */

    editorRunning = initialize_window();

    setup();

    while (editorRunning){
        processInput();
        update();
        render();
    }

    destroyWindow();

    return 0;

}

//-----------------------------------------------------------------------------------------------//
