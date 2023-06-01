// Hex.hp
#pragma once
#include "Interactable.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <cmath>
#include <cstddef>

typedef struct HexHash {
  std::size_t operator()(const HexCoords& coords) const {
    return std::hash<int>()(coords.q) ^ std::hash<int>()(coords.r);
  }
} HexHash;

typedef struct HexEq {
  bool operator()(const HexCoords& hex1, const HexCoords hex2) const {
    return (hex1.q == hex2.q && hex1.r == hex2.r);
  }
} HexEq;


class Hex : public Interactable, public sf::Shape {
public:
    explicit Hex();
    explicit Hex(HexCoords coords, float size, sf::Color fillColor, sf::Color outlineColor, int outlineThickness);

    sf::Color getFillColor() const {
        return _fillColor;
    }

    sf::Color getOutlineColor() const {
        return _outlineColor;
    }

    int getOutlineThickness() const {
        return _outlineThickness;
    }


    virtual std::size_t getPointCount() const;

    virtual sf::Vector2f getPoint(std::size_t index) const;
    
    static HexCoords screenToAxial(const sf::Vector2f& screen, const int& size);
    static sf::Vector2f axialToScreen(const HexCoords& axial, const int& size);
    bool operator==(const Hex& hex) const {
      return (this->_positionHex.q == hex._positionHex.q && this->_positionHex.r == hex._positionHex.r);
    }
    HexCoords getCoords() const {
      return _positionHex;
    }

    virtual void updatePosition() {
      this->setPosition(axialToScreen(_positionHex, _size));
    }
    
    //utilisé comme fonction de hashage pour les unordered_set 
private:
    static const float sq;
    sf::Color _fillColor;
    sf::Color _outlineColor;
    int _outlineThickness;
    sf::Vector2f _center;
    int _size;

};
