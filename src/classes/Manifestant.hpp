#ifndef MANIFESTANT_HPP
#define MANIFESTANT_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Interactable.hpp"
#include "Troupe.hpp"
class Manifestant : public Troupe {
 public:
  Manifestant() = default;
  Manifestant(std::string name, int size, HexCoords coords, Region *reg) : _customName(name), _size(size) {
    _name = "Manifestant";
    _camp = 0;
    _moral = 100;
    _region = reg;
    _positionHex = coords;

    if(!_texture.loadFromFile("../assets/manifestant.png")) {
			std::cout << "impossible de charger la texture" << std::endl;
		};
		sf::Vector2u imgSize(_texture.getSize());
		float imgWidth = (float) (imgSize.x);
		float imgHeight = (float) (imgSize.y);
		_sprite.setTexture(_texture);
		_sprite.setOrigin( imgWidth /2.0f, imgHeight /2.0f);
		_sprite.setScale(sf::Vector2f(0.5 * _region->getTileSize()  / imgWidth, 1 *  _region->getTileSize() /  imgHeight));
    //_shape.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
    //_shape.setFillColor(_color);
    //_shape.setSize(sf::Vector2f(10, _size));
    Grid grid = reg->getGrid();
    _sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
    this->updatePosition();
    Hex *hex = grid.getHexFromCoords(coords);
    hex->addEntity((Troupe*) this);
    
  };
  
  ~Manifestant() {};
  void updatePosition() override{
    _sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
  } 

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(_sprite, states);
  }

private:
  std::string _customName;
  //sf::Color _color;
  int _size;
  //sf::RectangleShape _shape;
  sf::Texture _texture;
  sf::Sprite _sprite;
};


#endif  // !MANIFESTANT_HPP
