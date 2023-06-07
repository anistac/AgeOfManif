#include "InfoGame.hpp"
#include "FontManager.hpp"
#include "Invoker.hpp"
#include <iostream>

void InfoGame::updateInfo(float _opinion, int _argentPeuple, int _argentGouv) {
  _rectangleBg.setSize(sf::Vector2f(900, 40));
  _rectangleBg.setPosition(0, 0);
  _rectangleBg.setFillColor(sf::Color::White);
  std::string txt =
      "Opinion : " + std::to_string(_opinion) +
      "      Argent du peuple : " + std::to_string(_argentPeuple) +
      "      Argent du Gouvernement : " + std::to_string(_argentGouv);
  _text.setString(txt);
  _text.setFont(FontManager::getInstance().getFont());
  _text.setCharacterSize(20);
  _text.setFillColor(sf::Color::Black);
  sf::FloatRect texteBounds = _text.getLocalBounds();
  _text.setOrigin(texteBounds.left, texteBounds.top);
  _text.setPosition(5, 10);
}

void InfoGame::draw(sf::RenderTarget &window, sf::RenderStates states) const {
  sf::View currView = window.getView();
  window.setView(window.getDefaultView());
  sf::RectangleShape turnInfoBox(sf::Vector2f(200, 200));
  turnInfoBox.setPosition(window.getSize().x - 200, 40);
  turnInfoBox.setFillColor(sf::Color::White);
  std::string txt = "Tour : " + std::to_string(Invoker::getCurrentTurn());

  sf::Text turnInfoText;
  turnInfoText.setString(txt);
  turnInfoText.setPosition(window.getSize().x - 200 + 5, 60);
  turnInfoText.setFont(FontManager::getInstance().getFont());
  turnInfoText.setCharacterSize(20);
  turnInfoText.setFillColor(sf::Color::Black);
  sf::Text remainingActionText;
  txt = "Actions restantes : " + std::to_string(Invoker::getRemainingActions());
  remainingActionText.setString(txt);
  remainingActionText.setPosition(window.getSize().x - 200 + 5, 80);
  remainingActionText.setFont(FontManager::getInstance().getFont());
  remainingActionText.setCharacterSize(20);
  remainingActionText.setFillColor(sf::Color::Black);
  window.draw(turnInfoBox, states);
  window.draw(_rectangleBg, states);
  window.draw(_text, states);
  window.draw(turnInfoBox, states);
  window.draw(turnInfoText, states);
  window.draw(remainingActionText, states);
  window.setView(currView);
}
