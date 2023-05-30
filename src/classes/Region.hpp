#ifndef REGION_HPP
#define REGION_HPP

//#include "Batiment.hpp"
//#include "Troupe.hpp"
#include "Batiment.hpp"
#include "Troupe.hpp"

#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
//class Batiment;
//class Troupe;

class Region {
public:
  Region();
  void renderRegion();

private:
  std::string name;
  std::vector<Batiment>  Batiments;
  std::vector<Troupe> Troupes;
  float opinion;
  sf::Texture tileSetTexture;
};

#endif // !REGION_HPP


