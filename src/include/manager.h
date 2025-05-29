#ifndef MANAGER_H
#define MANAGER_H
#pragma once

// LIBRARY IMPORTS
#include <vector>

// LOCAL IMPORTS
#include "instance.h"

//-----------------------------------------------------------------------------------------------//
// CLASS - FUNCTIONS + ATTRIBUTES

class Manager{

public:
Manager(){}

private:
std::vector<Instance*> instances;
Instance* currentInstance;

void addInstance(Instance* instance){ instances.push_back(instance);}
void setCurrentInstance(Instance* instance){ currentInstance = instance;}

protected:


};

//-----------------------------------------------------------------------------------------------//

#endif
