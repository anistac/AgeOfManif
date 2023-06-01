#ifndef MANIFESTER_HPP
#define MANIFESTER_HPP

#include "Command.hpp"
#include "Grid.hpp"
#include "CommandRegistry.hpp"
#include "Manifestant.hpp"

class Manifester : public Command {
public:
    ~Manifester() = default;
    Manifester() {
        CommandRegistry::addCmd<Manifestant, Hex>(this);
    };
    bool execute() override;
};

#endif // MANIFESTER_HPP
