// Hex.cpp
#include "Hex.hpp"
#include <algorithm>
#include <cmath>

const float Hex::sq = sqrt(3.0f) / 2.0f;

Hex::Hex(HexCoords coords, float size, sf::Color fillColor, sf::Color outlineColor, int outlineThickness)
    : _coords(coords), _size(size), _fillColor(fillColor), _outlineColor(outlineColor), _outlineThickness(outlineThickness) {
    _center = sf::Vector2f(_size / 2, _size / 2);
  this->setOrigin(_center);
  this->setFillColor(_fillColor);
  this->setOutlineColor(_outlineColor);
  this->setOutlineThickness(_outlineThickness);

  this->setPosition(axialToScreen(coords));
  update();

}
sf::Vector2f Hex::getPoint(std::size_t index) const {
  
  const float angle = M_PI / 180 * 60 * index;
  float x = _center.x + _size * std::cos(angle);
  float y = _center.y + _size * std::sin(angle);
  return sf::Vector2f(x, y);
}

std::size_t Hex::getPointCount() const {
    return 6;
}
sf::Vector2f Hex::axialToScreen(const HexCoords& axial) {
  float x = (3.0f/2.0f * axial.q) * _size +  _size / 2;
  float y = (sq * axial.q + std::sqrt(3) * axial.r)  * _size  +  _size * std::sqrt(3) / 2;
  return sf::Vector2f(x, y);
}
sf::Vector2f Hex::screenToAxial(const sf::Vector2f& screen) {
    float x = screen.x * std::sqrt(3) * (1 - 2 * ((int) screen.y % 2)) + _size;
    float y;
    return sf::Vector2f(x, y);
}

