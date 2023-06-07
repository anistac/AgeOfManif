#include "Region.hpp"
#include "ActionManager.hpp"
#include "BoutonAction.hpp"
#include "BuildPoliceStationCommand.hpp"
#include "BuildZADCommand.hpp"
#include "Command.hpp"
#include "CommandRegistry.hpp"
#include "DemonstrationCommand.hpp"
#include "DestroyCommand.hpp"
#include "DismentleCommand.hpp"
#include "Grid.hpp"
#include "HoverManager.hpp"
#include "InfoGame.hpp"
#include "Manifestant.hpp"
#include "MoveCommand.hpp"
#include "DemonstrationCommand.hpp"
#include "DismentleCommand.hpp"
#include "BuildPoliceStationCommand.hpp"
#include "BuildMairieCommand.hpp"
#include "BuildUsineCommand.hpp"
#include "BuildBarbecueCommand.hpp"
#include "BuildZADCommand.hpp"
#include "GiveInPeopleCommand.hpp"
#include "DestroyCommand.hpp"
#include "RoundAbout.hpp"
#include "PoliceStation.hpp"
#include "Usine.hpp"
#include "Mairie.hpp"
#include "Policier.hpp"
#include "Radicaux.hpp"
#include "Polititien.hpp"
#include "ZAD.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <cstddef>
#include <iostream>
#include <memory>

#define VISIBLE_WIDTH 700
#define VISIBLE_HEIGHT 600

Region::Region(sf::RenderWindow &win, std::string reg_name)
    : _reg_name(reg_name) {
  HoverManager hm(this);
  _hoverManager = hm;
  ActionManager am(this);
  _actionManager = am;

  sf::Font font; // Déclaration de la variable font
  _win = &win;
  _view = sf::View(sf::FloatRect(0, 0, VISIBLE_WIDTH, VISIBLE_HEIGHT));
  if (!WorldTexture.loadFromFile("../assets/Map1.png")) {
    std::cout << "Impossible de charger la map" << std::endl;
  }
  _barGame = InfoGame();
  WorldSprite.setTexture(WorldTexture);
  _mapSize = WorldSprite.getTexture()->getSize();
  unsigned int mapWidth = _mapSize.x;
  unsigned int mapHeight = _mapSize.y;

  _view.setCenter(static_cast<float>(mapWidth) / 2.f,
                  static_cast<float>(mapHeight) / 2.f);
  _win->setView(_view);
  std::cout << "map size: " << mapWidth << " x " << mapHeight << std::endl;

  _grid = Grid(sf::Vector2i(50, 50), 70);
  std::cout << "grid created" << std::endl;

  // Créer le rectangle blanc
  // Créer le texte "Actions :"
  sf::Text titleText("Actions :", font, 18);
  titleText.setPosition(1000, 1600);
  titleText.setFillColor(sf::Color::Black);

  Invoker::setCurrentRegion(this);

  DismentleCommand *disCmd = new DismentleCommand();
  CommandRegistry::addCmd<Policier, RoundAbout>(
      std::shared_ptr<Command>(disCmd));
  BuildZADCommand *buiZADCmd = new BuildZADCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiZADCmd));
  BuildMairieCommand *buiMaiCmd = new BuildMairieCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiMaiCmd));
  BuildUsineCommand *buiUsiCmd = new BuildUsineCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiUsiCmd));
  BuildBarbecueCommand *buiBarCmd = new BuildBarbecueCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiBarCmd));
  BuildPoliceStationCommand *buiPStCmd = new BuildPoliceStationCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiPStCmd));
  DestroyCommand *desCmd = new DestroyCommand();
  CommandRegistry::addCmd<PoliceStation>(std::shared_ptr<Command>(desCmd));
  CommandRegistry::addCmd<RoundAbout>(std::shared_ptr<Command>(desCmd));
  DemonstrationCommand *demCmd = new DemonstrationCommand();
  CommandRegistry::addCmd<Manifestant, RoundAbout>(std::shared_ptr<Command>(demCmd));
  MoveCommand *mvCmd = new MoveCommand();
  CommandRegistry::addCmd<Manifestant, Hex>(std::shared_ptr<Command>(mvCmd));
  CommandRegistry::addCmd<Policier, Hex>(std::shared_ptr<Command>(mvCmd));
  CommandRegistry::addCmd<Radicaux, Hex>(std::shared_ptr<Command>(mvCmd));
  CommandRegistry::addCmd<Polititien, Hex>(std::shared_ptr<Command>(mvCmd));
  GiveInPeopleCommand *givCmd = new GiveInPeopleCommand();
  CommandRegistry::addCmd<Mairie, Radicaux>(std::shared_ptr<Command>(givCmd));

  

  Manifestant *manifestant1 = new Manifestant("Manifestant1", 200, HexCoords(3, 0), (this));
  Manifestant *manifestant2 = new Manifestant("Manifestant2", 100, HexCoords(3, 1), (this));
  RoundAbout *roundabout1 = new RoundAbout("RP1", 200, HexCoords(5,0),(this));
  Usine *usine = new Usine("Usine", 200, HexCoords(2,1),(this));
  PoliceStation *policeStation = new PoliceStation("Station", 200, HexCoords(1,1), (this));
  
  Policier *policier = new Policier("Policier", 200, HexCoords(2,2), (this));

  _Troupes.push_back(manifestant1);
  _Troupes.push_back(manifestant2);
  _Batiments.push_back(roundabout1);
  _Batiments.push_back(policeStation);
  _Troupes.push_back(policier);
  _Batiments.push_back(usine);
}

void Region::handleEvent(sf::Event event) {
  // sf::Event event;
  _grid.clearGrid();
  _win->pollEvent(event);
  sf::View currView = _win->getView();
  sf::View newView = currView;
  if (event.type == sf::Event::MouseWheelScrolled) {
    if (event.mouseWheelScroll.delta > 0) {
      newView.zoom(0.9f);
    } else {
      newView.zoom(1.1f);
    }
  } else if (event.type == sf::Event::KeyPressed) {
    float moveSpeed = 100.0f;
    if (event.key.code == sf::Keyboard::Up) {
      newView.move(0, -moveSpeed);
      // newViewCenter.y -= moveSpeed;
      // if(viewCenter.y - _win->getSize().y/2 < 0 || viewCenter.x -
      // _win->getSize().x < 0) viewCenter.y+=moveSpeed;
    } else if (event.key.code == sf::Keyboard::Down) {
      newView.move(0, moveSpeed);
      // newViewCenter.y += moveSpeed;
    } else if (event.key.code == sf::Keyboard::Left) {
      newView.move(-moveSpeed, 0);
      // newViewCenter.x -= moveSpeed;
    } else if (event.key.code == sf::Keyboard::Right) {
      newView.move(moveSpeed, 0);
      // newViewCenter.x += moveSpeed;
    } else if (event.key.code == sf::Keyboard::R) {
      Region::selectedWin = 0;
      return;
    }
  } else if (event.type == sf::Event::MouseMoved) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
    sf::Vector2f worldPos = _win->mapPixelToCoords(mousePos);
    HexCoords hexCoords = Hex::screenToAxial(worldPos, _grid.getTileSize());
    Hex *hex = _grid.getHexFromPixel(worldPos);
    _grid.setHoveredHex(hex);
    _hoverManager.update();
  } else if (event.type == sf::Event::MouseButtonPressed) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
    sf::Vector2f worldPos = _win->mapPixelToCoords(mousePos);
    if (_actionManager.isInActionManagerBounds(mousePos)) {
      if (event.mouseButton.button == sf::Mouse::Left) {
        for (auto &action : _actionManager.getActions()) {
          action.aEteClique(mousePos);
        }
      }
    } else {
      HexCoords hexCoords = Hex::screenToAxial(worldPos, _grid.getTileSize());
      std::cout << "hex coords: " << hexCoords.q << ", " << hexCoords.r
                << std::endl;
      Hex *hex = _grid.getHexFromPixel(worldPos);
      if (event.mouseButton.button == sf::Mouse::Left) {
        _grid.setSelectedHex(hex);
      } else if (event.mouseButton.button == sf::Mouse::Right)
        _grid.removeSelectedHex(hex);
    }
    _actionManager.update();
  }

  float width = static_cast<float>(_win->getSize().x);
  float height = static_cast<float>(_win->getSize().y);
  float zoomFactor = newView.getSize().x / width;
  if (newView.getCenter().x - (width / 2) * zoomFactor < 0 ||
      newView.getCenter().y - (height / 2) * zoomFactor < 0 ||
      newView.getCenter().x + (width / 2) * zoomFactor > _mapSize.x ||
      newView.getCenter().y + (height / 2) * zoomFactor > _mapSize.y)
    newView = currView;
  _view = newView;
  _win->setView(_view);

  if (event.type == sf::Event::KeyPressed) {
  }

  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == sf::Mouse::Left) {
    // Mettre à jour la position de la souris
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*_win);

    // Vérifier si le bouton a été survolé ou cliqué
    if (event.type == sf::Event::MouseMoved) {
      // bouton1.estSurvole(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
    if (event.type == sf::Event::MouseButtonPressed) {
      sf::Vector2i mp = sf::Mouse::getPosition(*_win);
      // bouton1.aEteClique(sf::Vector2f(mp.x, mp.y));
    }
  }
}

void Region::makeTick() {
  _win->setView(_view);
  _win->draw(WorldSprite);
  _grid.renderGrid(*_win);

  for (auto batiment : _Batiments) {
    _win->draw(*batiment);
  }
  for (auto troupe : _Troupes) {
    _win->draw(*troupe);
  }
  _barGame.updateInfo(_opinion, _argentPeuple, _argentGouv);
  _win->draw(_barGame);
  _win->draw(_hoverManager);
  _win->draw(_actionManager);
}

void Region::deleteTroupe(Troupe *troupe) {
  _Troupes.erase(std::remove(_Troupes.begin(), _Troupes.end(), troupe),
                 _Troupes.end());
  delete troupe;
}

void Region::deleteBatiment(Batiment *batiment) {
  _Batiments.erase(std::remove(_Batiments.begin(), _Batiments.end(), batiment),
                   _Batiments.end());
  delete batiment;
}
