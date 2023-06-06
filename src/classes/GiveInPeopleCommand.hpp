#ifndef GIVEINPEOPLE_HPP
#define GIVEINPEOPLE_HPP

#include "Command.hpp"
#include "Grid.hpp"
#include "CommandRegistry.hpp"
#include "Interactable.hpp"
#include "Troupe.hpp"
#include "Batiment.hpp"
#include <cstddef>
#include <iostream>
#include <memory>

class GiveInPeopleCommand : public Command {
public:
    ~GiveInPeopleCommand() = default;
    GiveInPeopleCommand() {
        _name = "Céder au peuple";
        std::cout << "GiveInPeopleCommand added" << std::endl;
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};


#endif // GIVEINPEOPLE_HPP
