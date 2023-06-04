#include "BoutonAction.hpp"
#include "Command.hpp"
#include "FontManager.hpp"
#include <iostream>
BoutonAction::BoutonAction(const std::string &texte,
                           const sf::Vector2f &position,
                           const sf::Vector2f &taille, Action action)
    : m_estSurvole(false), m_aEteClique(false), _action(action) {
  m_rectangle.setSize(taille);
  m_rectangle.setFillColor(sf::Color::Blue);
  m_rectangle.setPosition(position);

  m_texte.setString(texte);
  m_texte.setFont(FontManager::getInstance().getFont());
  m_texte.setCharacterSize(20);
  m_texte.setFillColor(sf::Color::White);
  sf::FloatRect texteBounds = m_texte.getLocalBounds();
  m_texte.setOrigin(texteBounds.left + texteBounds.width / 2.0f,
                    texteBounds.top + texteBounds.height / 2.0f);
  m_texte.setPosition(position.x + taille.x / 2.0f,
                      position.y + taille.y / 2.0f);
}

bool BoutonAction::estSurvole(const sf::Vector2i &positionSouris) {
  sf::FloatRect boutonBounds = m_rectangle.getGlobalBounds();
  m_estSurvole = boutonBounds.contains((positionSouris.x), (positionSouris.y));
  if (m_estSurvole) {
    return true;
  } else {
    return false;
  }
}

bool BoutonAction::aEteClique(const sf::Vector2i &positionSouris) {

  sf::FloatRect boutonBounds = m_rectangle.getGlobalBounds();
  m_aEteClique = boutonBounds.contains((positionSouris.x), (positionSouris.y));
  if (m_aEteClique) {
    std::cout << "qlf" << std::endl;
    return Invoker::executeCommand(_action);

  } else {
    m_aEteClique = false;
    return false;
  }
}

void BoutonAction::draw(sf::RenderTarget &target,
                        sf::RenderStates states) const {
  target.draw(m_rectangle, states);
  target.draw(m_texte, states);
}
