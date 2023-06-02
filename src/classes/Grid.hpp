#ifndef GRID_HPP
#define GRID_HPP

#include "Hex.hpp"
#include "Interactable.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Grid {
public:
  Grid() = default;
  Grid(sf::Vector2i size, int tileSize);
  ~Grid() = default;

  void renderGrid(sf::RenderWindow &window);
  void setSize(sf::Vector2f size);
  Hex &getHexFromPixel(sf::Vector2f pixel);

  sf::Vector2i getSize();
  int getTileSize() const { return _tileSize; }
  void setHoveredHex(Hex &hex) { _hoveredHex = hex; }
  void setSelectedHex(Hex &hex);
  
  Hex& getHexFromCoords(HexCoords coords) { return _hexes[coords]; }

  std::vector<Hex> &getSelectedHexes() { return _selectedHexes; }
  void removeSelectedHex(Hex &hex);

  void clearGrid();

private:
  sf::Vector2i _size;
  int _tileSize;
  static const Hex def_hex;
  Hex _hoveredHex;
  std::vector<Hex> _selectedHexes;
  std::unordered_map<HexCoords, Hex, HexHash, HexEq> _hexes;
};

#endif // !GRID_HPP
