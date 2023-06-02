#ifndef MANIFESTANT_HPP
#define MANIFESTANT_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Interactable.hpp"
#include "Troupe.hpp"
class Manifestant : public Troupe, public sf::RectangleShape {
 public:
  Manifestant() = default;
  //{
  //   _customName = "Manifestant";
  //   _color = sf::Color::Red;
  //   _size = 50;
  //   _name = "Manifestant";
  //   _camp = 0;
  //   _moral = 100;
  //   _region = Region();
  //   _positionHex = HexCoords();
  //   this->setSize(sf::Vector2f(10, _size));
  //   this->setFillColor(_color);
  //   this->setPosition(Hex::axialToScreen(_positionHex, 70));
  //   this->update();
  // }
  //
  Manifestant(std::string name, sf::Color color, int size, HexCoords coords, Region reg) : _customName(name), _color(color), _size(size) {
    _name = "Manifestant";
    _camp = 0;
    _moral = 100;
    _region = reg;
    _positionHex = coords;
    this->setPosition(Hex::axialToScreen(_positionHex, _region.getTileSize()));
    this->setFillColor(_color);
    this->setSize(sf::Vector2f(10, _size));
    Grid grid = reg.getGrid();
    Hex hex = grid.getHexFromCoords(coords);
    hex.addEntity(*this);
    this->update();
    
  };
  
  ~Manifestant() {};
  void updatePosition() override{
    this->setPosition(Hex::axialToScreen(_positionHex, _region.getTileSize()));
  } 

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(*this, states);
  }

private:
  std::string _customName;
  sf::Color _color;
  int _size;
  Region _region;
};


#endif  // !MANIFESTANT_HPP
