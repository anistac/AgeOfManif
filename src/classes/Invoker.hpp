#ifndef INVOKER_HPP
#define INVOKER_HPP

#include "ActionType.hpp"
#include "Command.hpp"
#include <memory>
#include <vector>
// #include "Region.hpp"
class Region;
// Classe Invoker
class Invoker {
public:
  static void addCommand(std::shared_ptr<Command> command);
  static bool executeCommand(Action action);
  static void setCurrentRegion(Region *reg);
  static Region *getCurrentRegion() { return _reg; }
  static int getCurrentCamp() { return currentTurn % 2; }
  static int getCurrentTurn() { return currentTurn + 1; }
  static int getRemainingActions() { return _remainingActions; }

private:
  inline static std::vector<std::shared_ptr<Command>> commands;
  inline static Region *_reg;
  inline static int _remainingActions = 3;
  inline static int currentTurn = 0;
};
#endif // INVOKER_HPP
