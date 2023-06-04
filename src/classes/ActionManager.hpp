#ifndef ACTION_MANAGER_HPP
#define ACTION_MANAGER_HPP

#include "BoutonAction.hpp"
#include "Interactable.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
class EmptyInitiator;
//forward declaration
class Region;
class ActionManager : public sf::Drawable{

public:
  ActionManager() : _reg(nullptr){};
  ActionManager(Region &reg): _reg(&reg), _actions() {}
  void setCurrentRegion(Region &reg) { _reg = &reg; }
  ~ActionManager() = default;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void update();
  bool isInActionManagerBounds(sf::Vector2i mousePos);
  std::vector<BoutonAction> getActions() const { return _actions; }

private:
  Region *_reg;
  std::vector<BoutonAction> _actions;
  Interactable *_selectedEntities[2] = {nullptr, nullptr};
};

#endif // !ACTION_MANAGER_HPP

