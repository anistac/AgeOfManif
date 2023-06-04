#include "MoveCommand.hpp"
#include "Interactable.hpp"
#include "Region.hpp"
#include "Troupe.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool MoveCommand::execute(Interactable *init1, Interactable *init2) {
  Troupe *troupe = dynamic_cast<Troupe*>(init1) == nullptr ? dynamic_cast<Troupe*>(init2) : dynamic_cast<Troupe*>(init1);
  Hex *hex = dynamic_cast<Hex*>(init2) == nullptr ? dynamic_cast<Hex*>(init1) : dynamic_cast<Hex*>(init2);
  
  if (troupe == nullptr) {
    std::cout << "MoveCommand failed" << std::endl;
    return false;
  }
  std::cout << hex->getHexCoords().q << " " << hex->getHexCoords().r << std::endl;
  troupe->move(hex);
  std::cout << "MoveCommand executed" << std::endl;
    return true;
}
