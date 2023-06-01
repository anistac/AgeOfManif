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
    

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Age of Manifs");
    //___________________________________________________________________________________________________
    
    Menu menu(window);

    
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
// SWITCH
            switch(Win::selectedWin) {
                case 0:
                    menu.handleEvent();
                    break;
                case 1:
                    break;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    //showMain = true; // Repasse sur le showMain
                }
            }

            
        }         

        switch (Win::selectedWin)
        {
        case 0:
            menu.makeTick();
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}