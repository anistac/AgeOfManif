#ifndef HOVER_MANAGER_HPP
#define HOVER_MANAGER_HPP

#include "BoutonAction.hpp"
#include "Command.hpp"
#include "Interactable.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
// forward declaration
class Region;

typedef struct infos {
  std::string name;
  std::string description;
  std::string customName;
  int camp;
  Command *currAction;
} infos;

class HoverManager : public sf::Drawable {

public:
  HoverManager() : _reg(nullptr){};
  HoverManager(Region *reg) : _reg(reg){};
  void setCurrentRegion(Region *reg);
  ~HoverManager() = default;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void update();
  bool isInHiverManagerBounds(sf::Vector2i mousePos);

private:
  bool _visible;
  Region *_reg;
  std::vector<infos> _infos;
};

#endif // !HOVER_MANAGER_HPP
