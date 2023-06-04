#include "classes/ActionManager.hpp"
#include "classes/BoutonAction.hpp"
#include "classes/Hex.hpp"
#include "classes/InfoGame.hpp"
#include "classes/Manifestant.hpp"
//#include "classes/Manifester.hpp"
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "classes/Win.hpp"
using namespace std;
#include <iostream>
#include <vector>
#include <memory>

#include "classes/Menu.hpp"

int main() {

  sf::RenderWindow window(sf::VideoMode(820, 800), "Age of Manifs");
  //___________________________________________________________________________________________________
  Menu menu(window);
  Region region(window, "Ile de France");
  std::cout <<"selected win: " << Win::selectedWin << std::endl;  
  


  while (window.isOpen()) {
      // Gérer les événements
      
    sf::Event event;
    while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::R)
				{
					Region::selectedWin = 0; // Repasse sur le showMain
				}
			}

		
      // Fermer la fenêtre si l'utilisateur clique sur la croix en haut à droite
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
        Win::selectedWin = 0; 
      }
      switch(Win::selectedWin) {
        case 0:
          menu.handleEvent(event);
          break;
        case 1:
          region.handleEvent(event);
          break;
        default:
          menu.handleEvent(event);
          break; 
      }
    }
    window.clear(sf::Color::White);
    switch (Win::selectedWin) {
      case 0:
          menu.makeTick();
          break;
      case 1:
          region.makeTick();
          break;
      default:
          menu.makeTick();
          break;
    }
    window.display();
  }
  return 0;
}
