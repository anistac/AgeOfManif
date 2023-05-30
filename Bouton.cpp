#include <SFML/Graphics.hpp>
#include <string>

class Bouton {
public:
    Bouton(sf::Vector2f position, const std::string& text)
        : position(position), text(text)
    {
        rectangle.setSize(sf::Vector2f(150, 30));
        rectangle.setFillColor(sf::Color::Black);
        rectangle.setPosition(position);

        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(20);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(position);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(rectangle);
        window.draw(buttonText);
    }

    bool contains(sf::Vector2f point) const
    {
        return rectangle.getGlobalBounds().contains(point);
    }

private:
    sf::RectangleShape rectangle;
    sf::Text buttonText;
    sf::Vector2f position;
    std::string text;
};

