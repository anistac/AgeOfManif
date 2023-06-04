#include "MoveCommand.hpp"
#include "Interactable.hpp"
#include "Region.hpp"
#include "Troupe.hpp"
#include <iostream>
#ifndef DEBUG

#endif // !DEBUG

bool MoveCommand::execute(Interactable *init1, Interactable *init2) {
  Troupe *troupe = dynamic_cast<Troupe*>(init1);
  if (troupe == nullptr) {
    std::cout << "MoveCommand failed" << std::endl;
    return false;
  }
  troupe->move(dynamic_cast<Hex*>(init2));
  std::cout << "MoveCommand executed" << std::endl;
    return true;
}
