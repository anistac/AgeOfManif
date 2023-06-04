#ifndef DESTROY_COMMAND_HPP
#define DESTROY_COMMAND_HPP

#include "Command.hpp"
#include "Grid.hpp"
#include "CommandRegistry.hpp"
#include "Interactable.hpp"
#include "Troupe.hpp"
#include "Batiment.hpp"
// #include "Manifestant.hpp"
#include <cstddef>
#include <iostream>
#include <memory>

class DestroyCommand : public Command {
public:
    ~DestroyCommand() = default;
    DestroyCommand() {
        _name = "Detruire";
        _camp = -1;
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // DESTROY_COMMAND_HPP
