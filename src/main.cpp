#include "classes/BoutonAction.hpp"
#include "classes/InfoGame.hpp"
#include "classes/Manifester.hpp"
#include <SFML/Graphics.hpp>
#include "Game.hpp"
using namespace std;
#include <iostream>
#include <vector>
#include <memory>

#include "classes/Menu.hpp"
int Win::selectedWin = 0;
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(820, 800), "Age of Manifs");
    //___________________________________________________________________________________________________
    
    Menu menu(window);
    Region region(window, "Ile de France");
    menu.checkFont();

    
    while (window.isOpen())
    {
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Fermer la fenêtre si l'utilisateur clique sur la croix en haut à droite
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        
            switch(Win::selectedWin) {
                case 0:
                    menu.handleEvent(event);
                    break;
                case 1:
                    break;
            }
        }    
        window.clear(sf::Color::White);
        switch (Win::selectedWin)
        {
        case 0:
            menu.makeTick();
        case 1:
            region.makeTick();
            break;
        
        default:
            break;
        }
    window.display();
    }

    return 0;
}