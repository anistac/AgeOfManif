#include "InfoGame.hpp"
#include <iostream>

InfoGame::InfoGame(const sf::Font& police)
{
    m_rectangle.setSize(sf::Vector2f(800, 40));
    m_rectangle.setPosition(0, 0);

    texte.setString("Opinion :         %  Argent :             M*");
    texte.setFont(police);
    texte.setCharacterSize(20);
    texte.setFillColor(sf::Color::Black);
    sf::FloatRect texteBounds = texte.getLocalBounds();
    texte.setOrigin(texteBounds.left, texteBounds.top);
    texte.setPosition(5, 10);
}

void InfoGame::dessiner(sf::RenderWindow& window, int opinion, int argent)
{
    window.draw(m_rectangle);
    window.draw(texte);

    sf::Font font;
    // Chargez la police de caractères appropriée
    if (!font.loadFromFile("../assets/arial.ttf"))
    {
        // Gestion de l'erreur si la police ne peut pas être chargée
        std::cerr << "Erreur lors du chargement de la police de caractères." << std::endl;
        return;
    }
    
    sf::Text opi;
    opi.setFont(font);
    opi.setCharacterSize(20);
    opi.setFillColor(sf::Color::Black);
    opi.setPosition(100, 6);
    opi.setString(std::to_string(opinion));
    
    sf::Text arg;
    arg.setFont(font);
    arg.setCharacterSize(20);
    arg.setFillColor(sf::Color::Black);
    arg.setPosition(250, 6);
    arg.setString(std::to_string(argent));
    
    window.draw(opi);
    window.draw(arg);
}
