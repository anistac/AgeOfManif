#ifndef RADICAUX_HPP
#define RADICAUX_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Interactable.hpp"
#include "Troupe.hpp"
class Radicaux : public Troupe {
 public:
  Radicaux() = default;
  Radicaux(std::string name, int size, HexCoords coords, Region *reg) : _size(size) {
    _name = "Radicaux\n";
    _customName = name;
    _description = "Les radicaux sont la pour gagner";
    _camp = 0;
    _moral = 100;
    _region = reg;
    _positionHex = coords;

    if(!_texture.loadFromFile("../assets/radical.png")) {
			std::cout << "impossible de charger le radical" << std::endl;
		};
    sf::Vector2u imgSize(_texture.getSize());
    float imgWidth = (float) (imgSize.x);
    float imgHeight = (float) (imgSize.y);
    _sprite.setTexture(_texture);
    _sprite.setOrigin( imgWidth /2.0f, imgHeight /2.0f);
    _sprite.setScale(sf::Vector2f(1.5 * _region->getTileSize()  / imgWidth, 1.5 *  _region->getTileSize() /  imgHeight));
    Grid grid = reg->getGrid();
    _sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
    this->updatePosition();
    Hex *hex = grid.getHexFromCoords(coords);
    hex->addEntity((Troupe*) this);
    
  };
  
  ~Radicaux() {};
  void updatePosition() override{
    _sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
  } 

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(_sprite, states);
  }

private:
  std::string _customName;

  int _size;
  sf::Texture _texture;
  sf::Sprite _sprite;
};


#endif  // RADICAUX_HPP
