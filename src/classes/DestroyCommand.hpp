#ifndef DESTROY_COMMAND_HPP
#define DESTROY_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class DestroyCommand : public Command {
public:
    ~DestroyCommand() = default;
    DestroyCommand() {
        _name = "Detruire";
    };
    bool execute(Interactable *init1) override;
};

#endif // DESTROY_COMMAND_HPP