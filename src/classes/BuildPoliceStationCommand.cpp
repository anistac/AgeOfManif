#include "BuildPoliceStationCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildPoliceStationCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();

    //init1->addEntity(Interactable &entity);
    std::cout << "BuildPoliceStationCommand executed" << std::endl;
    return true;
}

