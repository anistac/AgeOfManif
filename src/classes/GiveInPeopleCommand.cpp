#include "GiveInPeopleCommand.hpp"
#include "Interactable.hpp"
#include "Demonstration.hpp"
#include "Mairie.hpp"
#include "Radicaux.hpp"
#include <iostream>
#include "Region.hpp" 


static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;

bool GiveInPeopleCommand::execute(Interactable *init1, Interactable *init2) {
    Mairie *batiment = dynamic_cast<Mairie*>(init1) == nullptr ? dynamic_cast<Mairie*>(init2) : dynamic_cast<Mairie*>(init1);
    Radicaux *troupe = dynamic_cast<Radicaux*>(init1) == nullptr ? dynamic_cast<Radicaux*>(init2) : dynamic_cast<Radicaux*>(init1);
    
    if(!batiment->getIsBesieged() == true){
		std::cout << "GiveInPeopleCommand failed" << std::endl;
		return false;
	}

    troupe->getRegion()->setOpinion(-10);
    troupe->getRegion()->setArgentG(-25000);
    batiment->setNotBesieged();

    std::cout << "GiveInPeopleCommand Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
