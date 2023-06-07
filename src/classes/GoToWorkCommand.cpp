#include "GoToWorkCommand.hpp"
#include "Interactable.hpp"
#include "Demonstration.hpp"
#include "Usine.hpp"
#include <iostream>
#include "Region.hpp" 


static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;

bool GoToWorkCommand::execute(Interactable *init1, Interactable *init2) {
    Usine *batiment = dynamic_cast<Usine*>(init1) == nullptr ? dynamic_cast<Usine*>(init2) : dynamic_cast<Usine*>(init1);
    Troupe *troupe = dynamic_cast<Troupe*>(init1) == nullptr ? dynamic_cast<Troupe*>(init2) : dynamic_cast<Troupe*>(init1);

    troupe->getRegion()->setOpinion(-10);
    troupe->getRegion()->setArgent(5000);

	Hex *hex = batiment->getRegion()->getGrid().getHexFromCoords(batiment->getHexCoords());
    troupe->move(hex);
    
    std::cout << "GoToWorkCommand Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
