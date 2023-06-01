#include "Manifester.hpp"
#include <iostream>

static std::unordered_map<std::pair<std::type_index, std::type_index>, Command*, CmdTypeHash, CmdTypeEq> _commands;
bool Manifester::execute() {
    // Implémentation spécifique de l'action 1
    std::cout << "Executé" << std::endl;
    return true; // Renvoyer true si l'exécution s'est bien déroulée
}
