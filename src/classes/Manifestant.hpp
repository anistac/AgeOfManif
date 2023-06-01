#ifndef MANIFESTANT_HPP
#define MANIFESTANT_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Interactable.hpp"
#include "Region.hpp"
#include "Troupe.hpp"
class Manifestant : public Troupe, public sf::RectangleShape {
 public:
  Manifestant() {
    _customName = "Manifestant";
    _color = sf::Color::Red;
    _size = 50;
    _name = "Manifestant";
    _camp = 0;
    _moral = 100;
    _region = Region();
    _positionHex = HexCoords();
    this->setSize(sf::Vector2f(10, _size));
    this->setFillColor(_color);
    this->setPosition(Hex::axialToScreen(_positionHex, 70));
    this->update();
  }

  Manifestant(std::string name, sf::Color color, int size, HexCoords &coords) : _customName(name), _color(color), _size(size) {
    _name = "Manifestant";
    _camp = 0;
    _moral = 100;
    _region = Region();
    _positionHex = coords;
    this->setPosition(Hex::axialToScreen(_positionHex, _region.getTileSize()));
    this->setFillColor(_color);
    this->setSize(sf::Vector2f(10, _size));
    this->update();
    
  };
  
  ~Manifestant() {};
  void updatePosition() {
    this->setPosition(Hex::axialToScreen(_positionHex, _region.getTileSize()));
  } 
private:
  std::string _customName;
  sf::Color _color;
  int _size;
};


#endif  // !MANIFESTANT_HPP
