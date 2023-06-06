#include "InfoGame.hpp"
#include <iostream>
#include "FontManager.hpp"

void InfoGame::updateInfo(float _opinion, int _argentPeuple, int _argentGouv) {
    _rectangleBg.setSize(sf::Vector2f(900, 40));
    _rectangleBg.setPosition(0, 0);
    _rectangleBg.setFillColor(sf::Color::White);
    std::string txt = "Opinion : " + std::to_string(_opinion) + "      Argent du peuple : " + std::to_string(_argentPeuple) + "      Argent du Gouvernement : " + std::to_string(_argentGouv);
    _text.setString(txt);
    _text.setFont(FontManager::getInstance().getFont());
    _text.setCharacterSize(20);
    _text.setFillColor(sf::Color::Black);
    sf::FloatRect texteBounds = _text.getLocalBounds();
    _text.setOrigin(texteBounds.left, texteBounds.top);
    _text.setPosition(5, 10);
    
}

void InfoGame::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    sf::View currView = window.getView();
    window.setView(window.getDefaultView());
    window.draw(_rectangleBg, states);
    window.draw(_text, states);
    window.setView(currView);
}
