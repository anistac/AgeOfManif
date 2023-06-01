#include "Region.hpp"
#include <iostream>

void Region::makeTick() {
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
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                // Vérifier si le bouton a été survolé ou cliqué
                if(event.type == sf::Event::MouseMoved)  {
                    bouton1.estSurvole(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                }
                if(event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mp = sf::Mouse::getPosition(window);
                    bouton1.aEteClique(sf::Vector2f(mp.x, mp.y));
                }
            }
    }
    
    if (showMain)
    {
        window.clear(sf::Color::Black);

        // Dessiner le mode showRegion ici
        barGame.dessiner(window, opinion, argent);
        window.draw(text);
        window.draw(menuBackground);
        window.draw(titleText);
        bouton1.dessiner(window);
    }
    
    */
}


void Region::handleEvent() {
    
}