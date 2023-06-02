#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class MoveCommand : public Command {
public:
    ~MoveCommand() = default;
    MoveCommand() {
        _name = "Move";
    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // !MOVE_COMMAND_HPP

