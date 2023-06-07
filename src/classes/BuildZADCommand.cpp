#include "BuildPoliceStationCommand.hpp"
#include "Interactable.hpp"
#include "ZAD.hpp"
#include "BuildZADCommand.hpp"
#include "Manifestant.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildZADCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();

    ZAD *zad = new ZAD("ZAD", 200, coords, Invoker::getCurrentRegion());

    Invoker::getCurrentRegion()->addBatiment(zad);

    zad->getRegion()->setOpinion(5);
    zad->getRegion()->setArgent(-5000);
    
    Manifestant *man1 = new Manifestant("Manifestant1", 200, coords, zad->getRegion());
    Manifestant *man2 = new Manifestant("Manifestant2", 200, coords, zad->getRegion());
    Manifestant *man3 = new Manifestant("Manifestant3", 200, coords, zad->getRegion());
    zad->getRegion()->addTroupe(man1);
    zad->getRegion()->addTroupe(man2);
    zad->getRegion()->addTroupe(man3);

    std::cout << "BuildZAD executed" << std::endl;
    return true;
}

