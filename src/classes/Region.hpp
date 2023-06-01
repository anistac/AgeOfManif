#ifndef REGION_HPP
#define REGION_HPP
//
// #include "Batiment.hpp"
// #include "Troupe.hpp"

#include <SFML/Graphics/View.hpp>
#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include "Grid.hpp"
#include "Win.hpp"
class Batiment;
class Troupe;

class Region : public Win {
public:
  Region(): _reg_name("dummy region") {
    
  };
  Region(sf::RenderWindow &win, std::string reg_name);
  
  void makeTick() override;
  void handleEvent(sf::Event event);
  int getTileSize() const {
    return _tileSize;
  }

private:
  std::string _reg_name;
  std::vector<std::shared_ptr<Batiment>>  _Batiments;
  std::vector<Troupe*> _Troupes;
  float _opinion;
  int _tileSize = 70;
  sf::Texture WorldTexture;
  sf::Sprite WorldSprite;
  
  // VIEW
  // sf::View view;
  Grid grid;
};

#endif // !REGION_HPP


