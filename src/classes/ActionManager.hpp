#ifndef ACTION_MANAGER_HPP
#define ACTION_MANAGER_HPP

#include "BoutonAction.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <vector>
//forward declaration
class Region;
class ActionManager : sf::Drawable{

public:
  ActionManager() : _reg(nullptr){};
  ActionManager(Region &reg): _reg(&reg) {};
  void setCurrentRegion(Region &reg) { _reg = &reg; }
  ~ActionManager() = default;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const {};
  void update();

private:
  Region *_reg;
  std::vector<BoutonAction> _actions;
  int _currEntityId;
};

#endif // !ACTION_MANAGER_HPP

