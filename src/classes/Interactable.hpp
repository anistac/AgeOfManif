#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP
#include <SFML/Graphics.hpp>
#include <cstddef>

#include "HexCoords.hpp"
class Command;
class Interactable {
public:
  virtual ~Interactable(){};
  virtual void updatePosition() = 0;
  void setHexPosition(HexCoords position) {
    _positionHex = position;
    updatePosition();
  }
  HexCoords getHexCoords() { return _positionHex; }
  const int getCamp() const { return _camp; }
  Command *getCurrAction() { return _currAction; }
  void setCurrAction(Command *action) { _currAction = action; }
  std::string getName() { return _name; }
  std::string getCustomName() { return _customName; }
  std::string getDescription() { return _description; }

protected:
  // sf::Texture _texture;
  // sf::Vector2f _positionWorld;
  std::string _name;
  std::string _customName;
  std::string _description;
  HexCoords _positionHex;
  int _camp;
  Command *_currAction = nullptr;
};

#endif // !INTERACTABLE_HPP
