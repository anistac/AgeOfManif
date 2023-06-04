#ifndef BUILDPOLICESTATION_COMMAND_HPP
#define BUILDPOLICESTATION_COMMAND_HPP

#include "Command.hpp"
#include "Interactable.hpp"

class BuildPoliceStationCommand : public Command {
public:
    ~BuildPoliceStationCommand() = default;
    BuildPoliceStationCommand() {
        _name = "Construire Poste de police";
    };
    bool execute(Interactable *init1) override;
};

#endif // BUILDPOLICESTATION_COMMAND_HPP