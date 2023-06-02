#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Interactable.hpp"
#include <string>
class Command {
public:
    // TODO: destructeur à hériter !!
    ~Command() = default;
    virtual bool execute(Interactable *init1, Interactable *init2) = 0;
    std::string getName() const { return _name; }
protected:
    std::string _name;
};

#endif // COMMAND_HPP
