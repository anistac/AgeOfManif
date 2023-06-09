#include "DestroyCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#include "Region.hpp"


bool DestroyCommand::execute(Interactable *init1, Interactable *init2) {
    Batiment *batiment = dynamic_cast<Batiment*>(init1) == nullptr ? dynamic_cast<Batiment*>(init2) : dynamic_cast<Batiment*>(init1);
    Hex *hex = batiment->getRegion()->getGrid().getHexFromCoords(init1->getHexCoords());
    hex->removeEntity(init1);

    
    batiment->getRegion()->deleteBatiment(batiment);
    std::cout << "DestroyCommand executed" << std::endl;
    return true;
}

