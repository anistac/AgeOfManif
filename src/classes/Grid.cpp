#include "Grid.hpp"
#include "Hex.hpp"
#include <SFML/System/Vector2.hpp>


Grid::Grid(sf::Vector2i size, int tileSize) : _size(size), _tileSize(tileSize) {
  sf::Color fillColor = sf::Color::Transparent;
  sf::Color outlineColor = sf::Color(255,255,255,100);
  int outlineThickness = 3;
  for(int i = 0; i <=_size.x; i++) {
      int q = floor(i/2);
      for(int j = 0 - q; j <= _size.y - q; j++) {
        HexCoords hexCoords(i,j);
        Hex hex(hexCoords, tileSize, fillColor, outlineColor, outlineThickness);
        _hexes.insert(hex);
        sf::Vector2f coords = hex.axialToScreen(hexCoords);
    }
  }
} 

void Grid::renderGrid(sf::RenderWindow& window) {
  for (auto const &hex : _hexes) {
    window.draw(hex);
  }
}
