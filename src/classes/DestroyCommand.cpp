#include "DestroyCommand.hpp"
#include "Interactable.hpp"
#include <iostream>
#include "Region.hpp"
#ifndef DEBUG

#endif // !DEBUG

bool DestroyCommand::execute(Interactable *init1) {
    init1->removeEntity(init1::_positionHex);
    //_reg.setArgent(1000);
    //_reg.setOpinion(-2);
    std::cout << "DestroyCommand executed" << std::endl;
    return true;
}
