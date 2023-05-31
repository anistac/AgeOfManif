#include "Game.hpp"
#include "classes/Grid.hpp"
#include "classes/Hex.hpp"
#include "classes/Manifestant.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

void Game::run() {
  unsigned int windowWidth = 800;
  unsigned int windowHeight = 600;
  unsigned int visibleWidth = 400;
  unsigned int visibleHeight = 300;
  
  
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Zoomable Map");
  sf::View view(sf::FloatRect(0, 0, visibleWidth, visibleHeight));
  window.setView(view);

  sf::Texture WorldTexture;
  if (!WorldTexture.loadFromFile("../assets/Map1.png")) {
    std::cout << "Impossible de charger la map" << std::endl;
  }

  sf::Sprite WorldSprite(WorldTexture);
  sf::Vector2u mapSize(WorldTexture.getSize());
 
  unsigned int mapWidth = mapSize.x;
  unsigned int mapHeight = mapSize.y;
  
  std::cout << "map size: " << mapWidth << " x " << mapHeight << std::endl;
  
  Grid grid(sf::Vector2i(50,50), 70);
  std::cout << "grid created" << std::endl;
  
  enum FogState { Unexplored, Explored, Visible };
  std::vector<std::vector<FogState>> fogOfWar(
      mapHeight, std::vector<FogState>(mapWidth, Unexplored));

  Manifestant manifestant;
  manifestant.setHexPosition(HexCoords(2,-2));
  manifestant.updatePosition();
 
  // Main game loop
  while (window.isOpen()) {
    sf::Event event;
    grid.clearGrid();
    window.clear();
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }  else if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
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
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);  
        HexCoords hexCoords = Hex::screenToAxial(worldPos, grid.getTileSize());
        Hex &hex = grid.getHexFromPixel(worldPos);
        grid.setHoveredHex(hex);
      } else if(event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
        HexCoords hexCoords = Hex::screenToAxial(worldPos, grid.getTileSize());
        Hex &hex = grid.getHexFromPixel(worldPos);
        grid.setSelectedHex(hex);
      }
    }
    window.clear();
    window.setView(view);

    // Update the game
    window.draw(WorldSprite);
    grid.renderGrid(window);
    window.draw(manifestant);
    window.display();
  }
}
