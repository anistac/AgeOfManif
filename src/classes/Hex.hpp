// Hex.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <cmath>
#include <cstddef>

typedef struct HexCoords{
  int q, r, s;
  HexCoords(int q, int r) : q(q), r(r), s(-q-r) {}
} HexCoords;

class Hex : public sf::Shape {
public:
    Hex();
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
    
    sf::Vector2f screenToAxial(const sf::Vector2f& screen);
    sf::Vector2f axialToScreen(const HexCoords& axial);

    HexCoords getCoords() const {
        return _coords;
    }
    
    //utilisé comme fonction de hashage pour les unordered_set 
    struct HexHash {
      std::size_t operator()(const Hex& hex) const {
          return std::hash<int>()(hex.getCoords().q) ^ std::hash<int>()(hex.getCoords().r);
      }
    };

    struct HexEq {
      bool operator()(const Hex& hex1, const Hex hex2) const {
        return (hex1.getCoords().q == hex2.getCoords().q && hex1.getCoords().r == hex2.getCoords().r);
    }


    };
private:
    static const float sq;
    sf::Color _fillColor;
    sf::Color _outlineColor;
    int _outlineThickness;
    sf::Vector2f _center;
    HexCoords _coords;
    int _size;

};

