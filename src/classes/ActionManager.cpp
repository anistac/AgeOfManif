#include "ActionManager.hpp"
#include "ActionType.hpp"
#include "BoutonAction.hpp"
#include "Command.hpp"
#include "CommandRegistry.hpp"
#include "Grid.hpp"
#include "Hex.hpp"
#include "Interactable.hpp"
#include "Manifestant.hpp"
#include "Region.hpp"
#include "Troupe.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

#define BAR_WIDTH 450
#define BAR_HEIGHT 200
#define BTN_SIZE 72
#define BTN_MARGIN 10

void ActionManager::update() {
  _actions.clear();
  _selectedEntities[0] = nullptr;
  _selectedEntities[1] = nullptr;
  std::vector<std::shared_ptr<Command>> cmds;
  std::vector<std::shared_ptr<Command>> unwantedCmds;
  Grid &grid = _reg->getGrid();
  std::vector<Hex *> selectedHexes = grid.getSelectedHexes();

  // aucun Hex selectionné

  if (selectedHexes.size() == 0) {
    return;
  }
  // un seul Hex sélectionné
  if (selectedHexes.size() == 1) {
    // aucune entité sur l'Hex sélectionné, tout va bien
    if (selectedHexes[0]->getEntities().size() == 0) {
      cmds = CommandRegistry::findAvailableCmds(selectedHexes[0]);
      if(cmds.size() >0 ) {
        for(auto const &cmd : cmds) {
          if(cmd->getcamp() != Invoker::getCurrentCamp()){
            std::cout << "on suppr " << cmd->getName() << std::endl;
            unwantedCmds.push_back(cmd);
          }
        }
        for(auto const &cmd : unwantedCmds) {
            cmds.erase(std::remove(cmds.begin(), cmds.end(), cmd), cmds.end());
        }

      }
      _selectedEntities[0] = selectedHexes[0];
      _selectedEntities[1] = nullptr;
    } else { // une entité, on doit vérifier le camp.
      if (selectedHexes[0]->getSelectedEntity()->getCamp() !=
          Invoker::getCurrentCamp())
        return;
      cmds = CommandRegistry::findAvailableCmds(
          selectedHexes[0]->getSelectedEntity());
      _selectedEntities[0] = selectedHexes[0]->getSelectedEntity();
      _selectedEntities[1] = nullptr;
    }
  }

  if (selectedHexes.size() == 2) {
    std::cout << "2 hexes" << std::endl;
    Interactable *int1 = selectedHexes[0]->getEntities().size() == 0
                             ? selectedHexes[0]
                             : selectedHexes[0]->getSelectedEntity();
    Interactable *int2 = selectedHexes[1]->getEntities().size() == 0
                             ? selectedHexes[1]
                             : selectedHexes[1]->getSelectedEntity();

    if ((int1->getCamp() >=0 && int1->getCamp() != Invoker::getCurrentCamp()) ||
        (int2->getCamp() >=0 && int2->getCamp() != Invoker::getCurrentCamp()))
      return;
    cmds = CommandRegistry::findAvailableCmds(int1, int2);
    _selectedEntities[0] = int1;
    _selectedEntities[1] = int2;
  }

  int i = 0;
  const int offsetX = _reg->getWinSize().x - BAR_WIDTH;
  const int offsetY = _reg->getWinSize().y - BAR_HEIGHT;
  _actions.clear();
  for (const auto &cmd : cmds) {
    Action action(_selectedEntities[0], _selectedEntities[1], cmd);

    int line =
        std::floor((cmds.size() * (BTN_SIZE + 2 * BTN_MARGIN) / BAR_WIDTH));
    BoutonAction bouton(
        cmd->getName(),
        sf::Vector2f(offsetX + BTN_MARGIN + i * (BTN_SIZE + BTN_MARGIN),
                     offsetY + BTN_MARGIN + line * (BTN_SIZE + BTN_MARGIN)),
        sf::Vector2f(BTN_SIZE, BTN_SIZE), action);
    _actions.push_back(bouton);
    i++;
  }
}

bool ActionManager::isInActionManagerBounds(sf::Vector2i mousePos) {
  const int offsetX = _reg->getWinSize().x - BAR_WIDTH;
  const int offsetY = _reg->getWinSize().y - BAR_HEIGHT;
  return mousePos.x > offsetX && mousePos.x < offsetX + BAR_WIDTH &&
         mousePos.y > offsetY && mousePos.y < offsetY + BAR_HEIGHT;
}

void ActionManager::draw(sf::RenderTarget &target,
                         sf::RenderStates states) const {
  sf::RectangleShape background;
  background.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
  background.setFillColor(sf::Color::White);
  background.setOrigin(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
  background.setPosition(sf::Vector2f(target.getSize().x, target.getSize().y));

  sf::View currView = target.getView();
  sf::View newView = target.getDefaultView();
  target.setView(newView);
  target.draw(background);
  for (auto &action : _actions) {
    target.draw(action);
  }
  target.setView(currView);
}
