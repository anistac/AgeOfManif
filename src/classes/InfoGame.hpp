#ifndef INFOGAME_HPP
#define INFOGAME_HPP
#include <SFML/Graphics.hpp>

class InfoGame : public sf::Drawable {
public:
    InfoGame() = default;
    void updateInfo(float opinion, int argent, int argentG);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    int _opinion;
    int _argentPeuple;
    int _argentGouv;
    sf::RectangleShape _rectangleBg;
    sf::Text _text;
};

#endif // INFOGAME_HPP