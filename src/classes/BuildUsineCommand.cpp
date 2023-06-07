#include "BuildUsineCommand.hpp"
#include "Interactable.hpp"
#include "Usine.hpp"
#include "Hex.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool BuildUsineCommand::execute(Interactable *init1, Interactable *init2) {
    HexCoords coords = init1->getHexCoords();
    Usine *usine = new Usine("Usine", 200, coords, Invoker::getCurrentRegion());
    Hex *hex = dynamic_cast<Hex*>(init1);
    Invoker::getCurrentRegion()->addBatiment(usine);

    usine->getRegion()->setOpinion(5);
    if(Invoker::getCurrentCamp() == 0){
        usine->getRegion()->setArgent(10000);
    }else{
        usine->getRegion()->setArgentG(10000);
    }

    std::cout << "BuildUsineCommand executed" << std::endl;
    return true;
}

