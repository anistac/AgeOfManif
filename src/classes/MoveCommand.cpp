#include "MoveCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool MoveCommand::execute(Interactable *init1, Interactable *init2) {
    init1->setHexPosition(init2->getHexCoords());
    std::cout << "MoveCommand executed" << std::endl;
    return true;
}
