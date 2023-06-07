#include "BuildMairieCommand.hpp"
#include "Interactable.hpp"
#include "Mairie.hpp"
#include "Polititien.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildMairieCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();
    Mairie *mairie = new Mairie("Mairie", 200, coords, Invoker::getCurrentRegion());
    Invoker::getCurrentRegion()->addBatiment(mairie);

    mairie->getRegion()->setOpinion(10);
    mairie->getRegion()->setArgent(-500);

    Polititien *pol = new Polititien("Polititien", 200, coords, mairie->getRegion());
    mairie->getRegion()->addTroupe(pol);
  

    std::cout << "BuildBarbecueCommand executed" << std::endl;
    return true;
}

