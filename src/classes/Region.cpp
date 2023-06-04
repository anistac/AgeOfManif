#include "Region.hpp"
#include "ActionManager.hpp"
#include "BoutonAction.hpp"
#include "Command.hpp"
#include "CommandRegistry.hpp"
#include "Grid.hpp"
#include "InfoGame.hpp"
#include "Manifestant.hpp"
#include "MoveCommand.hpp"
#include "DemonstrationCommand.hpp"
#include "BuildPoliceStationCommand.hpp"
#include "BuildZADCommand.hpp"
#include "DestroyCommand.hpp"
#include "RoundAbout.hpp"
#include "PoliceStation.hpp"
#include "ZAD.hpp"
#include "Win.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <cstddef>
#include <iostream>
#include <memory>

Region::Region(sf::RenderWindow &win, std::string reg_name) : _reg_name(reg_name) {
  ActionManager am(this);
  _actionManager = am;

  sf::Font font; // Déclaration de la variable font
  _win = &win;
  unsigned int visibleWidth = 400;
  unsigned int visibleHeight = 300;
  sf::View v = sf::View(sf::FloatRect(0, 0, visibleWidth, visibleHeight));
  v.setViewport(sf::FloatRect(0, 0, 1, 1));
  // sf::Texture WorldTexture;
  if (!WorldTexture.loadFromFile("../assets/Map1.png")) {
    std::cout << "Impossible de charger la map" << std::endl;
  }
  _barGame = InfoGame();
  WorldSprite.setTexture(WorldTexture);
  sf::Vector2u mapSize(WorldTexture.getSize());
  unsigned int mapWidth = mapSize.x;
  unsigned int mapHeight = mapSize.y;

  std::cout << "map size: " << mapWidth << " x " << mapHeight << std::endl;

  _grid = Grid(sf::Vector2i(50, 50), 70);
  std::cout << "grid created" << std::endl;

  // Créer le rectangle blanc
    // Créer le texte "Actions :"
  sf::Text titleText("Actions :", font, 18);
  titleText.setPosition(400, 600);
  titleText.setFillColor(sf::Color::Black);

  Invoker::setCurrentRegion(this);

  BuildZADCommand *buiZADCmd = new BuildZADCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiZADCmd));
  BuildPoliceStationCommand *buiPStCmd = new BuildPoliceStationCommand();
  CommandRegistry::addCmd<Hex>(std::shared_ptr<Command>(buiPStCmd));
  DestroyCommand *desCmd = new DestroyCommand();
  CommandRegistry::addCmd<PoliceStation>(std::shared_ptr<Command>(desCmd));
  CommandRegistry::addCmd<RoundAbout>(std::shared_ptr<Command>(desCmd));
  DemonstrationCommand *demCmd = new DemonstrationCommand();
  CommandRegistry::addCmd<Manifestant, RoundAbout>(std::shared_ptr<Command>(demCmd));
  MoveCommand *mvCmd = new MoveCommand();
  CommandRegistry::addCmd<Manifestant, Hex>(std::shared_ptr<Command>(mvCmd));
  Manifestant *manifestant1 = new Manifestant("Manifestant1", 200, HexCoords(3, 0), (this));
  Manifestant *manifestant2 = new Manifestant("Manifestant2", 100, HexCoords(3, 1), (this));
  RoundAbout *roundabout1 = new RoundAbout("RP1", 200, HexCoords(5,0),(this));
  PoliceStation *policeStation = new PoliceStation("Station", 200, HexCoords(0,0), (this));

  _Troupes.push_back(manifestant1);
  _Troupes.push_back(manifestant2);
  _Batiments.push_back(roundabout1);
  _Batiments.push_back(policeStation);
}

void Region::handleEvent(sf::Event event) {
  // sf::Event event;
  _grid.clearGrid();
  _win->pollEvent(event);
  sf::View view = _win->getView();
  if (event.type == sf::Event::MouseWheelScrolled) {
    if (event.mouseWheelScroll.delta > 0) {
      std::cout << "zoom in" << std::endl;
      view.zoom(0.9f); // Zoom in
    } else {
      view.zoom(1.1f); // Zoom out
    }
  } else if (event.type == sf::Event::KeyPressed) {
    float moveSpeed = 100.0f;
    if (event.key.code == sf::Keyboard::Up) {
      view.move(0, -moveSpeed);
    } else if (event.key.code == sf::Keyboard::Down) {
      view.move(0, moveSpeed);
    } else if (event.key.code == sf::Keyboard::Left) {
      view.move(-moveSpeed, 0);
    } else if (event.key.code == sf::Keyboard::Right) {
      view.move(moveSpeed, 0);
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

  _win->setView(view);

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

  _win->draw(WorldSprite);
  _grid.renderGrid(*_win);

  for (auto troupe : _Troupes) {
    _win->draw(*troupe);
  }
  
  for (auto batiment : _Batiments) {
    _win->draw(*batiment);
  }
  _barGame.updateInfo(_opinion, _argent);
  _win->draw(_barGame);
  _win->draw(_actionManager);
}

void Region::deleteTroupe(Troupe *troupe){
  _Troupes.erase(std::remove(_Troupes.begin(), _Troupes.end(), troupe), _Troupes.end());
  delete troupe;
}

void Region::deleteBatiment(Batiment *batiment){
  _Batiments.erase(std::remove(_Batiments.begin(), _Batiments.end(), batiment), _Batiments.end());
  delete batiment;


}
