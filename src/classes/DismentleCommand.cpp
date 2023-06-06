#include "DismentleCommand.hpp"
#include "Interactable.hpp"
#include "Policier.hpp"
#include "RoundAbout.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool DismentleCommand::execute(Interactable *init1, Interactable *init2) {
	RoundAbout *batiment = dynamic_cast<RoundAbout*>(init1) == nullptr ? dynamic_cast<RoundAbout*>(init2) : dynamic_cast<RoundAbout*>(init1);
	Policier *troupe = dynamic_cast<Policier*>(init1) == nullptr ? dynamic_cast<Policier*>(init2) : dynamic_cast<Policier*>(init1);
	

	if(!batiment->getIsOnFire() == true){
		std::cout << "Dismentle Command failed" << std::endl;
		return false;
	}
	batiment->setIsOffFire();
	Hex *hex = batiment->getRegion()->getGrid().getHexFromCoords(batiment->getHexCoords());
	troupe->move(hex);
	troupe->getRegion()->setOpinion(-5);
	troupe->getRegion()->setArgentG(-10000);

	std::cout << "DismentleCommand executed" << std::endl;
	return true;
}
