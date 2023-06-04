#ifndef REGION_HPP
#define REGION_HPP
//
// #include "Batiment.hpp"
// #include "Troupe.hpp"

#include "ActionManager.hpp"
#include "BoutonAction.hpp"
#include "Grid.hpp"
#include "InfoGame.hpp"
#include "Win.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <string>
#include <vector>

class Batiment;
class Troupe;

class Region : public Win {
public:
  Region(){};
  Region(sf::RenderWindow &win, std::string reg_name);
  ~Region() = default;
  void makeTick() override;
  void handleEvent(sf::Event event) override;
  int getTileSize() const { return _tileSize; }
  Grid &getGrid() { return _grid; }
  sf::Vector2f getWinSize() const { return sf::Vector2f(_win->getSize()); }

private:
  InfoGame _barGame;
  std::string _reg_name;
  std::vector<std::shared_ptr<Batiment>> _Batiments;
  std::vector<Troupe *> _Troupes;
  float _opinion;
  int _argent = 15600;
  int _tileSize = 70;
  sf::Texture WorldTexture;
  sf::Sprite WorldSprite;
  ActionManager _actionManager;
  // VIEW
  // sf::View view;
  Grid _grid;
};

#endif // !REGION_HPP
