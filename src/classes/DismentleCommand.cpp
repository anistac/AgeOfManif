#include "DismentleCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool DismentleCommand::execute(Interactable *init1) {
    init1->setHexPosition(init2->getHexCoords());
    std::cout << "DismentleCommand executed" << std::endl;
    return true;
}
