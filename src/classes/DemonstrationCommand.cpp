#include "DemonstrationCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#include "Region.hpp" 


static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;

bool DemonstrationCommand::execute(Interactable *init1, Interactable *init2) {
    Batiment *batiment = dynamic_cast<Batiment*>(init1) == nullptr ? dynamic_cast<Batiment*>(init2) : dynamic_cast<Batiment*>(init1);
    Troupe *troupe = dynamic_cast<Troupe*>(init1) == nullptr ? dynamic_cast<Troupe*>(init2) : dynamic_cast<Troupe*>(init1);
    troupe->getRegion().setOpinion(-10);
    //_region.setArgent(5000);
    // Implémentation spécifique de l'action 1
    std::cout << "DemonstrationCommand Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
