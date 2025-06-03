#ifndef INSTANCE_H
#define INSTANCE_H
#pragma once

// LIBRARY IMPORTS
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>
#include <tuple>

// LOCAL IMPORTS


//-----------------------------------------------------------------------------------------------//
// CLASS - FUNCTIONS + ATTRIBUTES

class Instance{

public:
    Instance(std::string n, int w, int h, int r) : name(n), width(w), height(h), running(r) { running = initialiseWindow();}
    int isRunning(){ return running;}
    void processInput();
    void render();

private:
    std::vector<std::string*> files;
    std::map<std::string, std::tuple<int, int>> bpLocations;
    std::vector<SDL_Event> eventBuffer;
    std::string currentFile;
    std::string name;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int width;
    int height;
    int running;

    int initialiseWindow(void);
    void destroyWindow();

protected:


};

//-----------------------------------------------------------------------------------------------//

#endif
