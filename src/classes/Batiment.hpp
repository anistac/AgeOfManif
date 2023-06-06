#ifndef BATIMENT_HPP
#define BATIMENT_HPP

#include "Interactable.hpp"
#include "Region.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/String.hpp>
#include "HexCoords.hpp"

#include <string>

class Batiment : public Interactable, public sf::Drawable {
public:
  Batiment() = default;
  virtual ~Batiment(){};
  std::string getName() { return _name; }
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
  Region *getRegion(){ return _region; }

protected:
  float _sante;
  Region *_region;
};

#endif // !BATIMENT_HPP

