#include "DemonstrationCommand.hpp"
#include "Interactable.hpp"
#include "Demonstration.hpp"
#include "RoundAbout.hpp"
#include <iostream>
#include "Region.hpp" 


static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;

bool DemonstrationCommand::execute(Interactable *init1, Interactable *init2) {
    RoundAbout *batiment = dynamic_cast<RoundAbout*>(init1) == nullptr ? dynamic_cast<RoundAbout*>(init2) : dynamic_cast<RoundAbout*>(init1);
    Troupe *troupe = dynamic_cast<Troupe*>(init1) == nullptr ? dynamic_cast<Troupe*>(init2) : dynamic_cast<Troupe*>(init1);
    
    if(batiment->getIsOnFire() == true){
		std::cout << "Demonstration Command failed" << std::endl;
		return false;
	}

    troupe->getRegion()->setOpinion(-10);
    troupe->getRegion()->setArgent(5000);
    batiment->setIsOnFire();
    troupe->move(batiment->getRegion()->getGrid().getHexFromCoords(batiment->getHexCoords()));

    std::cout << "DemonstrationCommand Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
