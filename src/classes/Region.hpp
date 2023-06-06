#ifndef REGION_HPP
#define REGION_HPP
//
// #include "Batiment.hpp"
// #include "Troupe.hpp"

#include "ActionManager.hpp"
#include "BoutonAction.hpp"
#include "Grid.hpp"
#include "HoverManager.hpp"
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
  int getOpinion() { return _opinion; }
  int getArgent() { return _argentPeuple; }
  int getArgentG() { return _argentGouv; }
  void setOpinion(int op) { _opinion += op; }
  void setArgent(int ar) { _argentPeuple += ar; }
  void setArgentG(int ar) { _argentGouv += ar; }
  void addTroupe(Troupe *troupe) { _Troupes.push_back(troupe); }
  void addBatiment(Batiment *batiment) { _Batiments.push_back(batiment); }
  void deleteTroupe(Troupe *troupe);
  void deleteBatiment(Batiment *batiment);
  void setBusy(Interactable *entity, int camp) {
    _busyEntities[camp].push_back(entity);
  };
  void setAllFree(int camp) { _busyEntities[camp].clear(); }
  sf::Vector2f getWinSize() const { return sf::Vector2f(_win->getSize()); }

private:
  InfoGame _barGame;
  std::string _reg_name;
  std::vector<Batiment *> _Batiments;
  std::vector<Troupe *> _Troupes;
  std::vector<Interactable *> _busyEntities[2];
  float _opinion = 50;
  int _argentPeuple = 15600;
  int _argentGouv = 100000;
  int _tileSize = 70;
  sf::Texture WorldTexture;
  sf::Sprite WorldSprite;
  sf::Vector2u _mapSize;
  ActionManager _actionManager;
  HoverManager _hoverManager;
 
  // VIEW
  sf::View _view;
  Grid _grid;
};

#endif // !REGION_HPP
