#include "Grid.hpp"
#include "Hex.hpp"
#include <SFML/System/Vector2.hpp>
#include <iostream>


Grid::Grid(sf::Vector2i size, int tileSize) : _size(size), _tileSize(tileSize) {
  sf::Color fillColor = sf::Color::Transparent;
  sf::Color outlineColor = sf::Color(255,255,255,100);
  int outlineThickness = 3;

  //creating grid
  for(int i = 0; i <=_size.x; i++) {
    int q = floor(i/2);
    for(int j = 0 - q; j <= _size.y - q; j++) {
      HexCoords hexCoords(i,j);
      Hex *hex = new Hex(hexCoords, tileSize, fillColor, outlineColor, outlineThickness);
      _hexes[HexCoords(i, j)] = hex;
      sf::Vector2f coords = hex->axialToScreen(hexCoords, tileSize);
    }
  }
} 

Hex* Grid::getHexFromPixel(sf::Vector2f pixel) {
  if(auto found = _hexes.find(Hex::screenToAxial(pixel, _tileSize)); found != _hexes.end()) {
      return found->second;
  } else {
    return _hexes.begin()->second;
  }
}


void Grid::setSelectedHex(Hex *hex) {
   if(std::find(_selectedHexes.begin(), _selectedHexes.end(), hex) != _selectedHexes.end()) {
    hex->toggleSelectedEntity();
  } else if(_selectedHexes.size() == 2) {
    _selectedHexes.erase(_selectedHexes.begin());
    _selectedHexes.push_back(hex);
  } else {
    _selectedHexes.push_back(hex);
  }
}

void Grid::removeSelectedHex(Hex *hex) {
    _selectedHexes.erase(std::remove(_selectedHexes.begin(), _selectedHexes.end(), hex), _selectedHexes.end());
}


void Grid::renderGrid(sf::RenderWindow& window) {
  for (auto &hex : _hexes) {
    if(*hex.second == _hoveredHex) {
      hex.second->setFillColor(sf::Color(255,255,255,100));
    }
    for(auto &selectedHex : _selectedHexes) {
      if(hex.second == selectedHex) {
        hex.second->setFillColor(sf::Color(240, 238, 192,200));
      }
    }
    window.draw(*hex.second);
  }
}

void Grid::clearGrid() {
  for (auto &hex : _hexes) {
    hex.second->setFillColor(sf::Color::Transparent);
  }
}
