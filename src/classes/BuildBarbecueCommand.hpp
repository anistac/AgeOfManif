#ifndef BUILDBARBECUE_COMMAND_HPP
#define BUILDBARBECUE_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class BuildBarbecueCommand : public Command {
public:
    ~BuildBarbecueCommand() = default;
    BuildBarbecueCommand() {
        _name = "Barbecue";
        _camp = 0;

    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // BUILDBARBECUE_COMMAND_HPP
