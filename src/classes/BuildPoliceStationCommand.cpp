#include "BuildPoliceStationCommand.hpp"
#include "Interactable.hpp"
#include "PoliceStation.hpp"
#include "Policier.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildPoliceStationCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();

    PoliceStation *policeStation = new PoliceStation("Station", 200, coords, Invoker::getCurrentRegion());

    Invoker::getCurrentRegion()->addBatiment(policeStation);

    policeStation->getRegion()->setOpinion(3);
    policeStation->getRegion()->setArgent(-5000);

    Policier *policier = new Policier("Policier poste", 200, coords, policeStation->getRegion());
    policeStation->getRegion()->addTroupe(policier);

    std::cout << "BuildPoliceStationCommand executed" << std::endl;
    return true;
}

