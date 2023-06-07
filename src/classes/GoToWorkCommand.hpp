#ifndef GOTOWORKCOMMAND_HPP
#define GOTOWORKCOMMAND_HPP

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

class GoToWorkCommand : public Command {
public:
    ~GoToWorkCommand() = default;
    GoToWorkCommand() {
        _name = "Aller travailler";

        std::cout << "GoToWorkCommand added" << std::endl;
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};


#endif // GOTOWORKCOMMAND_HPP
