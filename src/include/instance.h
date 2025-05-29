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
Instance(std::string n, int r) : name(n), running(r) {}

private:
std::vector<std::string*> files;
std::map<std::string, std::tuple<int, int>> bpLocations;
std::string currentFile;
std::string name;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int running;
int width;
int height;


int initialiseWindow(void);
void processInput();
void render();
void destroyWindow();

protected:


};

//-----------------------------------------------------------------------------------------------//

#endif
