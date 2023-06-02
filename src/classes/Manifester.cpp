#include "Manifester.hpp"
#include "Interactable.hpp"
#include <iostream>

static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;
bool Manifester::execute(Interactable *init1, Interactable *init2) {
    // Implémentation spécifique de l'action 1
    std::cout << "Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
