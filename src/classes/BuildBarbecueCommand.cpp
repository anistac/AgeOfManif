#include "BuildBarbecueCommand.hpp"
#include "Interactable.hpp"
#include "Barbecue.hpp"
#include "Radicaux.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildBarbecueCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();
    Barbecue *barbeuc = new Barbecue("Barbecue", 200, coords, Invoker::getCurrentRegion());
    Hex *hex = dynamic_cast<Hex*>(init1);
    hex->addEntity(barbeuc);
    Invoker::getCurrentRegion()->addBatiment(barbeuc);

    barbeuc->getRegion()->setOpinion(10);
    barbeuc->getRegion()->setArgent(-500);

    Radicaux *rad = new Radicaux("Radical", 200, coords, barbeuc->getRegion());
    barbeuc->getRegion()->addTroupe(rad);
  

    std::cout << "BuildBarbecueCommand executed" << std::endl;
    return true;
}

