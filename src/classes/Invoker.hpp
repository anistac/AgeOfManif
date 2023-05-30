#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <vector>
#include <memory>
#include "Command.hpp"

// Classe Invoker
class Invoker {
private:
    static std::vector<std::shared_ptr<Command>> commands ;

public:
    static void addCommand(std::shared_ptr<Command> command);
    static bool executeCommand(std::shared_ptr<Command> command);
};

#endif // INVOKER_HPP
