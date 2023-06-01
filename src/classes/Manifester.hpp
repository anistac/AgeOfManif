#ifndef MANIFESTER_HPP
#define MANIFESTER_HPP

#include "Command.hpp"
#include "Grid.hpp"
#include "CommandRegistery.hpp"
#include "Manifestant.hpp"
class Manifester : public Command {
public:
    ~Manifester() = default;
    Manifester() {
        CommandRegistry::addCmd<Manifestant, Grid>(this);
    };
    bool execute() override;
};

#endif // MANIFESTER_HPP
