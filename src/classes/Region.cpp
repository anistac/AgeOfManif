#include "Region.hpp"
#include "Grid.hpp"
#include "Manifestant.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>

Region::Region(sf::RenderWindow &win, std::string reg_name) : _reg_name(reg_name) {
    _win = &win;
 unsigned int visibleWidth = 400;
  unsigned int visibleHeight = 300;
  sf::View v = sf::View(sf::FloatRect(0, 0, visibleWidth, visibleHeight));
  

  // sf::Texture WorldTexture;
  if (!WorldTexture.loadFromFile("../assets/Map1.png")) {
    std::cout << "Impossible de charger la map" << std::endl;
  }

  WorldSprite.setTexture(WorldTexture);
  sf::Vector2u mapSize(WorldTexture.getSize());
  unsigned int mapWidth = mapSize.x;
  unsigned int mapHeight = mapSize.y;
  
  std::cout << "map size: " << mapWidth << " x " << mapHeight << std::endl;
  
  grid = Grid(sf::Vector2i(50,50), 70);
  std::cout << "grid created" << std::endl;
  
  // enum FogState { Unexplored, Explored, Visible };
  // std::vector<std::vector<FogState>> fogOfWar(
  //     mapHeight, std::vector<FogState>(mapWidth, Unexplored));
  //
  // Manifestant *manifestant = new Manifestant();
  // manifestant->setHexPosition(HexCoords(2,-2));
  // manifestant->updatePosition();
  // _Troupes.push_back(manifestant);
}

void Region::handleEvent(sf::Event event) {
  // sf::Event event;
  grid.clearGrid();
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
      }
  } else if(event.type == sf::Event::MouseMoved) {
      sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
      sf::Vector2f worldPos = _win->mapPixelToCoords(mousePos);  
      HexCoords hexCoords = Hex::screenToAxial(worldPos, grid.getTileSize());
      Hex &hex = grid.getHexFromPixel(worldPos);
      grid.setHoveredHex(hex);
  } else if(event.type == sf::Event::MouseButtonPressed) {
      sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
      sf::Vector2f worldPos = _win->mapPixelToCoords(mousePos);
      HexCoords hexCoords = Hex::screenToAxial(worldPos, grid.getTileSize());
      Hex &hex = grid.getHexFromPixel(worldPos);
      grid.setSelectedHex(hex);
  }
  _win->setView(view);
}

void Region::makeTick() {
  // _win->setView(view);

    // Update the game
  // std::cout << "rendering map" << std::endl;
  _win->draw(WorldSprite);
  grid.renderGrid(*_win);
  // for(auto *troupe : _Troupes) {
  //   // _win->draw(*troupe);
  // }
  // _win->display();
}
    /*

    // Créer le rectangle blanc
    sf::RectangleShape menuBackground(sf::Vector2f(450, 200));
    menuBackground.setPosition(400,600);

    // Créer le texte "Actions :"
    sf::Text titleText("Actions :", font, 18);
    titleText.setPosition(400, 600);
    titleText.setFillColor(sf::Color::Black);

    Invoker invoker;
    Manifester *manifesterCommand = new Manifester;
    std::shared_ptr<Command> cmd(manifesterCommand);
    BoutonAction bouton1("Action 1", font, sf::Vector2f(610, 675), sf::Vector2f(50, 50), invoker, cmd);
    //BoutonAction bouton2("Action 2", font, sf::Vector2f(670, 675), sf::Vector2f(50, 50));
    //BoutonAction bouton3("Action 3", font, sf::Vector2f(730, 675), sf::Vector2f(50, 50));

    // Créer le rectangle blanc Bar haute
    sf::RectangleShape barAffichage(sf::Vector2f(800, 40));
    barAffichage.setPosition(0,0);

    InfoGame barGame(font);
    int opinion = 65;
    int argent = 15600;

    bool showMain = true;
    int buttonPressed;

    // Gérer les événements
    sf::Event event;
    while (_win.pollEvent(event))
    {

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::R)
            {
                showMain = true; // Repasse sur le showMain
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {   
                // Mettre à jour la position de la souris
                sf::Vector2i mousePosition = sf::Mouse::getPosition(_win->;

                // Vérifier si le bouton a été survolé ou cliqué
                if(event.type == sf::Event::MouseMoved)  {
                    bouton1.estSurvole(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                }
                if(event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mp = sf::Mouse::getPosition(_win->;
                    bouton1.aEteClique(sf::Vector2f(mp.x, mp.y));
                }
            }
    }
    
    if (showMain)
    {
        _win->clear(sf::Color::Black);

        // Dessiner le mode showRegion ici
        barGame.dessiner(_win-> opinion, argent);
        _win->draw(text);
        _win->draw(menuBackground);
        _win->draw(titleText);
        bouton1.dessiner(_win->;
    }
    
    */

