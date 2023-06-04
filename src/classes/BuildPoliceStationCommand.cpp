#include "BuildPoliceStationCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildPoliceStationCommand::execute(Interactable *init1) {
    //init1->setHexPosition(init2->getHexCoords());
    //init1->addEntity(Interactable &entity);
    std::cout << "BuildPoliceStationCommand executed" << std::endl;
    return true;
}
