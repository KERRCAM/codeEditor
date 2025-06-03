// LIBRARY IMPORTS
#include <iostream>
#include <SDL2/SDL.h>

// LOCAL IMPORTS
#include "include/globals.h"
#include "include/manager.h"
#include "include/instance.h"
#include "include/keyMaps.h"

//-----------------------------------------------------------------------------------------------//

int main(){

    Instance* i1 = new Instance("i1", 800, 500, 1);

    Manager* manager = new Manager(); // TODO - need to setup multiple windows simultaneous inputs
    manager -> addInstance();

    while (i1 -> isRunning()){
        i1 -> processInput();
    }

    return 0;
}

//-----------------------------------------------------------------------------------------------//
