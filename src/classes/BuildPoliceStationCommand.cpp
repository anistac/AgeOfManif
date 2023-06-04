#include "BuildPoliceStationCommand.hpp"
#include "Interactable.hpp"
#include "PoliceStation.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildPoliceStationCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();
    PoliceStation *policeStation = new PoliceStation("Station", 200, coords, Invoker::getCurrentRegion());
    Hex *hex = dynamic_cast<Hex*>(init1);
    hex->addEntity(policeStation);
    Invoker::getCurrentRegion()->addBatiment(policeStation);

    std::cout << "BuildPoliceStationCommand executed" << std::endl;
    return true;
}

