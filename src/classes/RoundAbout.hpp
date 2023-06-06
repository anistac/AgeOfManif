#ifndef ROUNDABOUT_HPP
#define ROUNDABOUT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "Interactable.hpp"
#include "Batiment.hpp"
class RoundAbout : public Batiment {
public:
	RoundAbout() = default;

	RoundAbout(std::string name, int size, HexCoords coords, Region *reg) : _customName(name), _size(size) {
    _customName = "Rond Point";
    _camp = -1;
    _sante = 100.0f;
    _region = reg;
    _positionHex = coords;

	if(!_texture.loadFromFile("../assets/rond_point.png")) {
		std::cout << "impossible de charger la texture" << std::endl;
	};
	if(!_texturefeu.loadFromFile("../assets/feu_dem.png")) {
		std::cout << "impossible de charger la texture feu" << std::endl;
	};
	sf::Vector2u imgSize(_texture.getSize());
	float imgWidth = (float) (imgSize.x);
	float imgHeight = (float) (imgSize.y);
	_sprite.setTexture(_texture);
	_sprite.setOrigin( imgWidth /2.0f, imgHeight /2.0f);
	_sprite.setScale(sf::Vector2f(2.5 * _region->getTileSize()  / imgWidth, 2.5 *  _region->getTileSize() /  imgHeight));

	_spritefeu.setTexture(_texturefeu);
	sf::Vector2u textureSize = _texturefeu.getSize();
	_spritefeu.setOrigin(textureSize.x / 2, textureSize.y / 2);
	_spritefeu.setScale(sf::Vector2f(1 * _region->getTileSize()  / imgWidth, 1 *  _region->getTileSize() /  imgHeight));
    Grid &grid = reg->getGrid();
	_sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));

	_spritefeu.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
	this->updatePosition();
    Hex *hex = grid.getHexFromCoords(coords);
    hex->addEntity((Batiment*) this);
	}

	~RoundAbout() {
		_sprite.setTexture(sf::Texture());
		_spritefeu.setTexture(sf::Texture());
	};

void updatePosition() override{
  _sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
} 

void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
  target.draw(_sprite, states);
	if(_isOnFire == true){
		target.draw(_spritefeu, states);
	}
}

void setIsOnFire(){ _isOnFire = true; }
void setIsOffFire() { _isOnFire = false; }
bool getIsOnFire() { return _isOnFire; }



private:
std::string _customName;
int _size;
sf::Texture _texture;
sf::Sprite _sprite;
sf::Texture _texturefeu;
sf::Sprite _spritefeu;
bool _isOnFire = false;
};
#endif