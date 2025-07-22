#ifndef MANAGER_H
#define MANAGER_H
#pragma once

// LIBRARY IMPORTS
#include <vector>

// LOCAL IMPORTS
#include "instance.h"
#include "instanceRenderer.h"

//-----------------------------------------------------------------------------------------------//
// CLASS - FUNCTIONS + ATTRIBUTES

class Manager{

public:
    Manager();

private:
    std::vector<SDL_Event> eventBuffer;
    std::vector<Instance*> instances;

    void processInput();
    void quitApplication();

protected:


};

//-----------------------------------------------------------------------------------------------//

#endif
