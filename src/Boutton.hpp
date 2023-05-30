#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const sf::Vector2f& position, const std::string& label);

    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePosition) const;
    std::string getLabel() const;

private:
    sf::RectangleShape m_shape;
    sf::Text m_text;
};

#endif // BUTTON_HPP
