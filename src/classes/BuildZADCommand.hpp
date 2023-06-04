#ifndef BUILDZAD_COMMAND_HPP
#define BUILZAD_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class BuildZADCommand : public Command {
public:
    ~BuildZADCommand() = default;
    BuildZADCommand() {
        _name = "Construire Rond point";
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // BUILDZAD_COMMAND_HPP