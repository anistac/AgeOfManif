#include <iostream>
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

void Win::makeTick(){

    bool showMain = true;
    // Gérer les événements
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Fermer la fenêtre si l'utilisateur clique sur la croix en haut à droite
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::R)
            {
                showMain = true; // Repasse sur le showMain
            }
        }

        // Si l'utilisateur clique sur le bouton gauche de la souris
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {   
            // Mettre à jour la position de la souris
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            // Vérifier si le bouton a été survolé ou cliqué
            if(event.type == sf::Event::MouseMoved)  {
                bouton1.estSurvole(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
            }
            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mp = sf::Mouse::getPosition(window);
                bouton1.aEteClique(sf::Vector2f(mp.x, mp.y));
            }

            for (int i = 0; i < buttons.size(); ++i) {
                const auto& button = buttons[i];
                if (sf::Mouse::getPosition(window).x >= button.getPosition().x &&
                    sf::Mouse::getPosition(window).x <= button.getPosition().x + button.getSize().x &&
                    sf::Mouse::getPosition(window).y >= button.getPosition().y &&
                    sf::Mouse::getPosition(window).y <= button.getPosition().y + button.getSize().y)
                {
                    buttonPressed = i;
                    showMain = false;
                    text.setString(regionNames[buttonPressed]); // définir le texte à afficher
                }
            }   
        }
    }         
}