#include <SFML/Graphics.hpp>
#include "Interactable.hpp"
#include "Invoker.hpp"
#include "Command.hpp"
#include <iostream>
#include "Region.hpp"

void Invoker::setCurrentRegion(Region *reg) {
  _reg = reg;
}

void Invoker::addCommand(std::shared_ptr<Command> command) {
    commands.push_back(command);
}

bool Invoker::executeCommand(Action action) {
  std::cout << "oeoeoe invocation maggle eoeooeoeoeo on est la rpz" << std::endl;
    // Chercher la commande dans le vecteur
    // auto it = std::find_if(commands.begin(), commands.end(), [&](const auto& cmd) {
    //     return cmd.get() == &command;
    // });

     // if (it != commands.end()) {
    //     // Exécuter la commande trouvée
    //     return (*it)->execute();
    // }
  _reg->getGrid().unselectAll();
  if(action.cmd->execute(action.initiator1, action.initiator2)) {
    Invoker::_reg->setBusy(action.initiator1, Invoker::getCurrentCamp());
    if(action.initiator2 != nullptr)
      Invoker::_reg->setBusy(action.initiator2, Invoker::getCurrentCamp());
    action.initiator1->setCurrAction(action.cmd.get());
    _remainingActions--;
    if(_remainingActions == 0) {
      _remainingActions = 3;
      _reg->setAllFree(Invoker::getCurrentCamp());
      currentTurn++;

      std::cout << "Turn " << currentTurn << std::endl;
      return true;
    } 
  }
  return false;
    
}
