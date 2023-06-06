#ifndef MAIRIE_HPP
#define MAIRIE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "Interactable.hpp"
#include "Batiment.hpp"
#include "Invoker.hpp"

class Mairie : public Batiment {
public:
	Mairie() = default;

	Mairie(std::string name, int size, HexCoords coords, Region *reg) : _customName(name), _size(size) {
		_customName = "ZAD";
		_camp = 1;
		_sante = 100.0f;
		_region = reg;
		_positionHex = coords;

	if(!_texture.loadFromFile("../assets/mairie.png")) {
		std::cout << "impossible de charger la texture" << std::endl;
	};
	if(!_textureasiege.loadFromFile("../assets/manif.png")) {
		std::cout << "impossible de charger la texture asiege" << std::endl;
	};
	sf::Vector2u imgSize(_texture.getSize());
	float imgWidth = (float) (imgSize.x);
	float imgHeight = (float) (imgSize.y);
	_sprite.setTexture(_texture);
	_sprite.setOrigin( imgWidth /2.0f, imgHeight /2.0f);
	_sprite.setScale(sf::Vector2f(2 * _region->getTileSize()  / imgWidth, 2 *  _region->getTileSize() /  imgHeight));

	_spriteasiege.setTexture(_textureasiege);
	sf::Vector2u textureSize = _textureasiege.getSize();
	_spriteasiege.setOrigin(textureSize.x / 2, textureSize.y / 2);
	_spriteasiege.setScale(sf::Vector2f(1 * _region->getTileSize()  / imgWidth, 1 *  _region->getTileSize() /  imgHeight));

	Grid &grid = reg->getGrid();
	_sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
	this->updatePosition();
		Hex *hex = grid.getHexFromCoords(coords);
		hex->addEntity((Batiment*) this);
	}

	~Mairie() {};
	void updatePosition() override{
		_sprite.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
	} 

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
		if(_isBesieged == true){
			target.draw(_spriteasiege, states);
			target.draw(_sprite, states);
		}else{
			target.draw(_sprite, states);
		}
	}

	void setIsBesieged(){ _isBesieged = true; }
	void setNotBesieged() { _isBesieged = false; }
	bool getIsBesieged() { return _isBesieged; }

	private:
	std::string _customName;
	int _size;
	sf::Texture _texture;
	sf::Sprite _sprite;

	sf::Texture _textureasiege;
	sf::Sprite _spriteasiege;
	bool _isBesieged = true;
};
#endif //MAIRIE_HPP