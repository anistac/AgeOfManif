#ifndef TROUPE_HPP
#define TROUPE_HPP

#include "Hex.hpp"
#include "Interactable.hpp"
#include "Region.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/String.hpp>
#include <iostream>

class Troupe : public Interactable, public sf::Drawable {
public:
  Troupe() = default;
  Troupe(std::string name, int camp, Region *region, float moral)
      : _name(name), _camp(camp), _region(region), _moral(moral){};
  virtual ~Troupe(){};
  std::string getName() { return _name; }
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override = 0;
  void move(Hex *hex) {
    std::cout << "move" << std::endl;
    Grid &grid= _region->getGrid();
    std::cout << "grid" << std::endl;
    Hex *currHex = grid.getHexFromCoords(_positionHex);
    std::cout << "currHex " << currHex->getHexCoords().q << std::endl;
    currHex->removeEntity(this);
    // Hex *currHex = _region->getGrid().getHexFromCoords(_positionHex);
    hex->addEntity(this);
    this->setHexPosition(hex->getHexCoords());
  }
  Region *getRegion() { return _region; }
protected:
  std::string _name;
  int _camp;
  Region *_region;
  float _moral;
};

#endif // !TROUPE_HPP
