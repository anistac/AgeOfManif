#ifndef MANIFESTER_HPP
#define MANIFESTER_HPP

#include "Command.hpp"
#include "Grid.hpp"
#include "CommandRegistry.hpp"
#include "Interactable.hpp"
#include "Manifestant.hpp"
#include <cstddef>
#include <iostream>
#include <memory>

// CommandRegistry cmdRegistry;

class Manifester : public Command {
public:
    ~Manifester() = default;
    Manifester() {
        _name = "Manifester";

        std::cout << "manifester added" << std::endl;
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // MANIFESTER_HPP
