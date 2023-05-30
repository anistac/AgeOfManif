#ifndef GRID_HPP
#define GRID_HPP

#include "Hex.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_set>



class Grid {
public:
  Grid();
  Grid(sf::Vector2i size, int tileSize);
  ~Grid() = default;
  
  void renderGrid(sf::RenderWindow& window);
  void setSize(sf::Vector2f size);
  Hex getHexFromPixel(sf::Vector2f pixel);

  sf::Vector2i getSize();
private:
  sf::Vector2i _size;
  int _tileSize;
  static const Hex def_hex;
  std::unordered_set<Hex, Hex::HexHash, Hex::HexEq> _hexes;
};

#endif // !GRID_HPP
