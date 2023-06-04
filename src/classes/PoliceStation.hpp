#ifndef POLICESTATION_HPP
#define POLICESTATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "Interactable.hpp"
#include "Batiment.hpp"
class PoliceStation : public Batiment {
public:
	PoliceStation() = default;

	PoliceStation(std::string name, int size, HexCoords coords, Region *reg) : _size(size) {
    _name = "Station de police";
    _customName = name;
    _description = "La police est la pour vous proteger";
    _camp = 1;
    _sante = 100.0f;
    _region = reg;
    _positionHex = coords;

		if(!_texture.loadFromFile("../assets/police.png")) {
			std::cout << "impossible de charger la texture" << std::endl;
		};
		sf::Vector2u imgSize(_texture.getSize());
		float imgWidth = (float) (imgSize.x);
		float imgHeight = (float) (imgSize.y);
		_sprite.setTexture(_texture);
		_sprite.setOrigin( imgWidth /2.0f, imgHeight /2.0f);
		_sprite.setScale(sf::Vector2f(3 * _region->getTileSize()  / imgWidth, 3 *  _region->getTileSize() /  imgHeight));
    Grid &grid = reg->getGrid();
		_sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
		this->updatePosition();
    Hex *hex = grid.getHexFromCoords(coords);
    hex->addEntity((Batiment*) this);
	}

	~PoliceStation() {};
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
#endif //POLICESTATION_HPP
