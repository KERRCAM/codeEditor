// LIBRARY IMPORTS


// LOCAL IMPORTS
#include "include/manager.h"

//-----------------------------------------------------------------------------------------------//

void Manager::addInstance(){

    int i;
    if (sizeof(instances) == 0){ i = 0;}
    else {i = sizeof(instances) / sizeof(instances[0]);}

    std::string name = "i1";

    Instance* newInstance = new Instance(name, 800, 500, 1);

    instances.push_back(newInstance);

}

//-----------------------------------------------------------------------------------------------//
