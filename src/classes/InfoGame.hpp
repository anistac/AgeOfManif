#ifndef INFOGAME_HPP
#define INFOGAME_HPP
#include <SFML/Graphics.hpp>

class InfoGame {
public:
    InfoGame(const sf::Font& police);
    void dessiner(sf::RenderWindow& window, int opinion, int argent);
    
private:
    sf::RectangleShape m_rectangle;
    sf::Text texte;    
};

#endif // INFOGAME_HPP