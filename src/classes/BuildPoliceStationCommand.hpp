#ifndef BUILDROUNDABOUT_COMMAND_HPP
#define BUILDROUNDABOUT_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class BuildPoliceStationCommand : public Command {
public:
    ~BuildPoliceStationCommand() = default;
    BuildPoliceStationCommand() {
        _name = "Poste\nde\npolice";
        _camp = 1;

    };
    bool execute(Interactable *init1, Interactable *init2) override;
};

#endif // BUILDPOLICESTATION_COMMAND_HPP
