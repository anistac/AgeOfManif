#ifndef BUILDMAIRIE_COMMAND_HPP
#define BUILDMAIRIE_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class BuildMairieCommand : public Command {
public:
    ~BuildMairieCommand() = default;
    BuildMairieCommand() {
        _name = "Mairie";
        _camp = 1;

    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // BUILDMAIRIE_COMMAND_HPP
