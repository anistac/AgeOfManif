// Hex.cpp
#include "Hex.hpp"
#include <algorithm>
#include <cmath>

const float Hex::sq = sqrt(3.0f) / 2.0f;

Hex::Hex(): _size(0), _fillColor(sf::Color::Transparent), _outlineColor(sf::Color::Transparent), _outlineThickness(0) {
  _positionHex = HexCoords(-1,-1);
}

Hex::Hex(HexCoords coords, float size, sf::Color fillColor, sf::Color outlineColor, int outlineThickness)
    : _size(size), _fillColor(fillColor), _outlineColor(outlineColor), _outlineThickness(outlineThickness) {
  _positionHex = coords;
  _center = sf::Vector2f(_size / 2, _size / 2);
  this->setOrigin(_center);
  this->setFillColor(_fillColor);
  this->setOutlineColor(_outlineColor);
  this->setOutlineThickness(_outlineThickness);

  this->setPosition(axialToScreen(coords, size));
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
sf::Vector2f Hex::axialToScreen(const HexCoords& axial, const int& size) {
  float x = (3.0f/2.0f * axial.q) * size +  size / 2;
  float y = (sq * axial.q + std::sqrt(3) * axial.r)  * size  +  size * std::sqrt(3) / 2;
  return sf::Vector2f(x, y);
}
HexCoords Hex::screenToAxial(const sf::Vector2f& screen, const int& size) {
  float px = (screen.x - size/2) / size;
  float py = (screen.y - (size * std::sqrt(3) / 2)) / size;
  float qf = 2.0f/3.0f * px;
  float qr = -1/3.0f * px + std::sqrt(3)/3.0f * py;
  
  //rounding 
  int q = std::round(qf);
  int r = std::round(qr);
  int s = std::round(-qf-qr);

  float q_diff = std::abs(q - qf);
  float r_diff = std::abs(r - qr);
  float s_diff = std::abs(s - (-qf-qr));

  if(q_diff > r_diff && q_diff > s_diff)
    q = -r-s;
  else if(r_diff > s_diff)
    r = -q-s;
  else
    s = -q-r;

  return HexCoords(q, r);
}

