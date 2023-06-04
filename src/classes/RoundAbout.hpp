#ifndef ROUNDABOUT_HPP
#define ROUNDABOUT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Interactable.hpp"
#include "Batiment.hpp"
class RoundAbout : public Batiment {
public:
	RoundAbout() = default;

	RoundAbout(std::string name, int size, HexCoords coord, Region *reg) : _customName(name), _size(size) {
    _name = "Round About";
    _camp = 0;
    _sante = 100;
    _region = reg;
    _positionHex = coords;

		_image.loadFromFile("../assets/.png");
    _image.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
    _image.setSize(sf::Vector2f(10, _size));
    Grid &grid = reg->getGrid();
    Hex *hex = grid.getHexFromCoords(coords);
    hex->addEntity((Troupe*) this);
	};

	~RoundAbout() {};
  void updatePosition() override{
    _image.setPosition(Hex::axialToScreen(_positionHex, _region->getTileSize()));
  } 

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(_image, states);
  }

	public Whatevergoesinhere getImage() {
    return image;
  }

private:

sf::Texture _image;

