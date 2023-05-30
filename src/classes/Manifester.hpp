#ifndef MANIFESTER_HPP
#define MANIFESTER_HPP

#include "Command.hpp"

class Manifester : public Command {
public:
    ~Manifester() = default;
    Manifester() = default;
    bool execute() override;
};

#endif // MANIFESTER_HPP
