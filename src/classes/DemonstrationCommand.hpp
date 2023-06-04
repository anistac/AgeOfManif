#ifndef DEMONSTRATIONCOMMAND_HPP
#define DEMONSTRATIONCOMMAND_HPP

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

// CommandRegistry cmdRegistry;

class DemonstrationCommand : public Command {
public:
    ~DemonstrationCommand() = default;
    DemonstrationCommand() {
        _name = "DemonstrationCommand";

        std::cout << "DemonstrationCommand added" << std::endl;
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // DEMONSTRATIONCOMMAND_HPP
