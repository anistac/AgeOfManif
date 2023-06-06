#ifndef BUILDUSINE_COMMAND_HPP
#define BUILDUSINE_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class BuildUsineCommand : public Command {
public:
    ~BuildUsineCommand() = default;
    BuildUsineCommand() {
        _name = "Usine";
        _camp = -1;

    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // BUILDUSINE_COMMAND_HPP
