#include "Region.hpp"
#include "ActionManager.hpp"
#include "Command.hpp"
#include "CommandRegistry.hpp"
#include "Grid.hpp"
#include "Manifestant.hpp"
#include "MoveCommand.hpp"
#include "Win.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include "BoutonAction.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include "InfoGame.hpp"
#include "DemonstrationCommand.hpp"

Region::Region(sf::RenderWindow &win, std::string reg_name) : _reg_name(reg_name){
	ActionManager am(*this);
  _actionManager = am;

  sf::Font font; // Déclaration de la variable font
	_win = &win;
	unsigned int visibleWidth = 400;
  unsigned int visibleHeight = 300;
  sf::View v = sf::View(sf::FloatRect(0, 0, visibleWidth, visibleHeight));

	
  
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
  
  _grid = Grid(sf::Vector2i(50,50), 70);
  std::cout << "grid created" << std::endl;

	// Créer le rectangle blanc
	sf::RectangleShape menuBackground(sf::Vector2f(450, 200));
	menuBackground.setPosition(400,600);

	// Créer le texte "Actions :"
	sf::Text titleText("Actions :", font, 18);
	titleText.setPosition(400, 600);
	titleText.setFillColor(sf::Color::Black);

	Invoker invoker;
	// Manifester manifesterCommand;
	CommandRegistry::addCmd<std::nullptr_t, Hex>(std::shared_ptr<Command>(std::shared_ptr<Command>(new DemonstrationCommand())));
  CommandRegistry::addCmd<Troupe, Hex>(std::shared_ptr<Command>(new MoveCommand()));
	//CommandRegistry::addCmd<Hex, std::nullptr_t>(std::shared_ptr<Command>(new BuildPoliceStationCommand()));
	//CommandRegistry::addCmd<Batiment, std::nullptr_t>(std::shared_ptr<Command>((new DestroyCommand())));

  // std::shared_ptr<Command> cmd(manifesterCommand);
	// BoutonAction bouton1("Action 1", sf::Vector2f(610, 675), sf::Vector2f(50, 50), invoker, cmd);
	//BoutonAction bouton2("Action 2", font, sf::Vector2f(670, 675), sf::Vector2f(50, 50));
	//BoutonAction bouton3("Action 3", font, sf::Vector2f(730, 675), sf::Vector2f(50, 50));
	// _Troupes.push_back(manifestant1);
  // Créer le rectangle blanc Bar haute

}

void Region::handleEvent(sf::Event event) {
  // sf::Event event;
  _grid.clearGrid();
  _win->pollEvent(event);
  sf::View view = _win->getView();
  if (event.type == sf::Event::MouseWheelScrolled) {
    if (event.mouseWheelScroll.delta > 0) {
      std::cout << "zoom in" << std::endl;
      view.zoom(0.9f);  // Zoom in
    } else {
      view.zoom(1.1f);  // Zoom out
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
      } else	if (event.key.code == sf::Keyboard::R) {
			  Region::selectedWin = 0;
        return;

		  }
  } else if(event.type == sf::Event::MouseMoved) {
      sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
      sf::Vector2f worldPos = _win->mapPixelToCoords(mousePos);  
      HexCoords hexCoords = Hex::screenToAxial(worldPos, _grid.getTileSize());
      Hex &hex = _grid.getHexFromPixel(worldPos);
      _grid.setHoveredHex(hex);
  } else if(event.type == sf::Event::MouseButtonPressed) {
      

      sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
      sf::Vector2f worldPos = _win->mapPixelToCoords(mousePos);
      HexCoords hexCoords = Hex::screenToAxial(worldPos, _grid.getTileSize());
      Hex &hex = _grid.getHexFromPixel(worldPos);
      if(event.mouseButton.button == sf::Mouse::Left) {
        _grid.setSelectedHex(hex);

      }else if(event.mouseButton.button == sf::Mouse::Right)
        _grid.removeSelectedHex(hex);   
      _actionManager.update();
  }
  _win->setView(view);



	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){   
		// Mettre à jour la position de la souris
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*_win);

		// Vérifier si le bouton a été survolé ou cliqué
		if(event.type == sf::Event::MouseMoved)  {
			// bouton1.estSurvole(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
		}
		if(event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i mp = sf::Mouse::getPosition(*_win);
			// bouton1.aEteClique(sf::Vector2f(mp.x, mp.y));
		}
	}

}

void Region::makeTick() {

  // Update the game
  // std::cout << "rendering map" << std::endl;
  _win->draw(WorldSprite);
  _grid.renderGrid(*_win);
  HexCoords coords(2,-2);

  Manifestant manifestant1("Manifestant1", sf::Color::Blue, 200, coords, (*this));
  // _Troupes.push_back(manifestant1);
  // Créer le rectangle blanc Bar haute
  //_win->draw(manifestant1);
  // for(auto &troupe : _Troupes) {
  //   // std::cout << troupe->getHexCoords().q << std::endl;
  //   // _win->draw((sf::Drawable&)*troupe);
  // }
	// Dessiner le mode showRegion ici
  _barGame.updateInfo(_opinion, _argent);
	_win->draw(_barGame);
	
	// _win->draw(text);
	// _win->draw(menuBackground);
	// bouton1.dessiner(_win);

}

