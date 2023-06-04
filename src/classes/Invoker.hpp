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

private:
    inline static std::vector<std::shared_ptr<Command>> commands;
    inline static Region* _reg;
};
#endif // INVOKER_HPP
