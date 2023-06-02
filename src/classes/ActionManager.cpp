#include "ActionManager.hpp"
#include "BoutonAction.hpp"
#include "Command.hpp"
#include "Grid.hpp"
#include "Hex.hpp"
#include "Interactable.hpp"
#include "Region.hpp"
#include "CommandRegistry.hpp"
#include "Troupe.hpp"
#include <iostream>
typedef struct Action {
  std::string name;
  std::function<void()> action;
  Action(std::string name, std::function<void()> action): name(name), action(action) {};
} Action;


void ActionManager::update() {
  std::vector<std::shared_ptr<Command>> cmds;
  Grid grid = _reg->getGrid();
  std::vector<Hex> selectedHexes = grid.getSelectedHexes();
  // aucun Hex selectionné
 
  if(selectedHexes.size() == 0) {
    return;
  }
  // un seul Hex sélectionné
  if(selectedHexes.size() == 1) {
    // aucune entité sur l'Hex sélectionné
    if(selectedHexes[0].getEntities().size() == 0) {
      cmds = CommandRegistry::findAvailableCmds(nullptr, selectedHexes[0]);
    } else {
      cmds = CommandRegistry::findAvailableCmds(nullptr, selectedHexes[0].getSelectedEntity());
    }
  }

  if(selectedHexes.size() == 2) {
    cmds = CommandRegistry::findAvailableCmds(selectedHexes[0].getSelectedEntity(), selectedHexes[1]);
    cmds[0]->execute(selectedHexes[0].getSelectedEntity(), &(selectedHexes[1]));
  }

  for(const auto &cmd : cmds) {
    std::cout << cmd->getName()<< std::endl;
  }
  // aucune entité sur l'Hex sélectionné
  // if(selectedHexes[0].getEntities().size() == 0 || selectedHexes[1].getEntities().size() == 0) {
  //   
  // }   
}




  

