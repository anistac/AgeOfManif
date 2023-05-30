#include "Game.hpp"
#include "classes/Grid.hpp"
#include "classes/Hex.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

// sf::ConvexShape createHex(float size) {
//   sf::ConvexShape hex(6);
//   for(int i=0; i < 6; i++) {
//     float a = 2.0f * M_PI / 6.0F * (i+ 0.5f);
//     hex.setPoint(i, sf::Vector2f(size * std::cos(a), size * std::sin(a)));
//   }
//   return hex;
// }
//
void Game::run() {
  unsigned int windowWidth = 800;
  unsigned int windowHeight = 600;
  unsigned int visibleWidth = 400;
  unsigned int visibleHeight = 300;
  unsigned int gridWidth = 80;
  unsigned int gridHeight = 80;
  
  
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                          "Zoomable Map");
  sf::View view(sf::FloatRect(0, 0, visibleWidth, visibleHeight));
  window.setView(view);

  // Load tileset and fog textures
  sf::Texture WorldTexture;
  if (!WorldTexture.loadFromFile("../assets/Map1.png")) {
    // Handle the error
    std::cout << "wtf ??" << std::endl;
  }
  std::cout << "texture loaded" << std::endl;
  sf::Sprite WorldSprite(WorldTexture);
  sf::Vector2u mapSize(WorldTexture.getSize());
  unsigned int mapWidth = mapSize.x;
  unsigned int mapHeight = mapSize.y;
  std::cout << "map size: " << mapWidth << " x " << mapHeight << std::endl;
  Grid grid(sf::Vector2i(50,50), 70);
  std::cout << "grid created" << std::endl;
  // Initialize the fog of war array
  enum FogState { Unexplored, Explored, Visible };
  std::vector<std::vector<FogState>> fogOfWar(
      mapHeight, std::vector<FogState>(mapWidth, Unexplored));
  std::cout << "created fog" << std::endl;
  // for (int y = (int)hexHeight / 2; y < mapHeight; y += hexHeight) {
  //   for (int x = (int)hexWidth / 2; x < mapWidth; x += hexWidth) {
  //     fogOfWar[y][x] = Visible;
  //   }
  // }
  std::cout << "debug: fog defined" << std::endl;

  // Main game loop
  while (window.isOpen()) {
    sf::Event event;
    
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
      }
    }
    
    window.setView(view);

    // Update the game

    window.clear();
    window.draw(WorldSprite);
    grid.renderGrid(window);
    window.display();
  }
}
