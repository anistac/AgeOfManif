#include "DemonstrationCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#include "Region.hpp" 


static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;
bool DemonstrationCommand::execute(Interactable *init1, Interactable *init2) {
    //_region.setOpinion(-10);
    //_region.setArgent(5000);
    // Implémentation spécifique de l'action 1
    std::cout << "DemonstrationCommand Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
