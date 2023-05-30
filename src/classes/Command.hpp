#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
    // TODO: destructeur à hériter !!
    ~Command() = default;
    virtual bool execute() = 0;
};

#endif // COMMAND_HPP
