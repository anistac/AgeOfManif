#include "BuildPoliceStationCommand.hpp"
#include "Interactable.hpp"
#include "ZAD.hpp"
#include "BuildZADCommand.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildZADCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();
    ZAD *zad = new ZAD("ZAD", 200, coords, Invoker::getCurrentRegion());
    Hex *hex = dynamic_cast<Hex*>(init1);
    hex->addEntity(zad);
    Invoker::getCurrentRegion()->addBatiment(zad);

    std::cout << "BuildZAD executed" << std::endl;
    return true;
}

