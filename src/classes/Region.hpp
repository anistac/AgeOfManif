#ifndef REGION_HPP
#define REGION_HPP
//
// #include "Batiment.hpp"
// #include "Troupe.hpp"

#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include "Win.hpp"
class Batiment;
class Troupe;

class Region : public Win {
public:
  Region(): _reg_name("dummy region") {
    
  };
  Region(sf::RenderWindow &win) {
    _win = &win;
  }
  void makeTick() override;
  int getTileSize() const {
    return _tileSize;
  }
private:
  std::string _reg_name;
  std::vector<std::shared_ptr<Batiment>>  _Batiments;
  std::vector<std::shared_ptr<Troupe>> _Troupes;
  float _opinion;
  int _tileSize = 70;
  sf::Texture tileSetTexture;
};

#endif // !REGION_HPP


