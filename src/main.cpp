// LIBRARY IMPORTS
#include <iostream>
#include <SDL2/SDL.h>

// LOCAL IMPORTS
#include "include/globals.h"
#include "include/manager.h"
#include "include/instance.h"
#include "include/input.h"
#include "include/keyMaps.h"

//-----------------------------------------------------------------------------------------------//

int main(){

    //running = initialize_window();

    Instance* i1 = new Instance("i1", 800, 500, 1);

    Manager* manager = new Manager();
    manager -> addInstance();

    while (i1 -> isRunning()){
        i1 -> processInput();
    }

    destroyWindow();

    return 0;
}

//-----------------------------------------------------------------------------------------------//
