#include "Invoker.hpp"
#include "Command.hpp"
#include "Interactable.hpp"
#include "Region.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void Invoker::setCurrentRegion(Region *reg) { _reg = reg; }

void Invoker::addCommand(std::shared_ptr<Command> command) {
  commands.push_back(command);
}

bool Invoker::executeCommand(Action action) {
  _reg->getGrid().unselectAll();
  if (action.cmd->execute(action.initiator1, action.initiator2)) {
    Invoker::_reg->setBusy(action.initiator1, Invoker::getCurrentCamp());
    if (action.initiator2 != nullptr)
      Invoker::_reg->setBusy(action.initiator2, Invoker::getCurrentCamp());
    action.initiator1->setCurrAction(action.cmd.get());
    _remainingActions--;
    if (_remainingActions == 0) {
      _remainingActions = 3;
      currentTurn++;

      _reg->setAllFree(Invoker::getCurrentCamp());

      std::cout << "Turn " << currentTurn << std::endl;
      return true;
    }
  }
  return false;
}
