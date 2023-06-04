#ifndef DISMENTLECOMMAND_HPP
#define DISMENTLECOMMAND_HPP

#include "Command.hpp"
#include "Grid.hpp"
#include "CommandRegistry.hpp"
#include "Interactable.hpp"
#include "Manifestant.hpp"
#include <cstddef>
#include <iostream>
#include <memory>

// CommandRegistry cmdRegistry;

class DismentleCommand : public Command {
public:
    ~DismentleCommand() = default;
    DismentleCommand() {
        _name = "DismentleCommand";

        std::cout << "DismentleCommand added" << std::endl;
    };
    bool execute(Interactable *init1) override;
};

#endif // DISMENTLECOMMAND_HPP
