#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP
#include <SFML/Graphics.hpp>
#include <cstddef>

#include "HexCoords.hpp"

class Interactable {
 public:
  virtual ~Interactable(){};
  virtual void updatePosition() = 0;
  void setHexPosition(HexCoords position) {
    _positionHex = position;
    updatePosition();
  }
  HexCoords getHexCoords() {
    return _positionHex;
  }
 protected:
  // sf::Texture _texture;
  // sf::Vector2f _positionWorld;
  HexCoords _positionHex;
};

#endif  // !INTERACTABLE_HPP
