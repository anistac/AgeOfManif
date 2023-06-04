#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <vector>
#include <memory>
#include "Command.hpp"
#include "ActionType.hpp"
// #include "Region.hpp"
class Region;
// Classe Invoker
class Invoker {
public:
    static void addCommand(std::shared_ptr<Command> command);
    static bool executeCommand(Action action);
    static void setCurrentRegion(Region *reg);
    static Region* getCurrentRegion() { return _reg; }
    static int getCurrentCamp() { return currentTurn % 2; }
private:
    inline static std::vector<std::shared_ptr<Command>> commands;
    inline static Region* _reg;
    inline static int _remainingActions = 3;
    inline static int currentTurn = 0;
};
#endif // INVOKER_HPP
