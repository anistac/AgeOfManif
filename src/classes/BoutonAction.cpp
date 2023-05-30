#include <iostream>
#include "BoutonAction.hpp"
#include "Command.hpp"
BoutonAction::BoutonAction(const std::string& texte, const sf::Font& police, const sf::Vector2f& position, const sf::Vector2f& taille, Invoker& invoker, std::shared_ptr<Command> cmd)
    : m_estSurvole(false), m_aEteClique(false), cmd(cmd)
{
    m_rectangle.setSize(taille);
    m_rectangle.setFillColor(sf::Color::Blue);
    m_rectangle.setPosition(position);

    m_texte.setString(texte);
    m_texte.setFont(police);
    m_texte.setCharacterSize(20);
    m_texte.setFillColor(sf::Color::White);
    sf::FloatRect texteBounds = m_texte.getLocalBounds();
    m_texte.setOrigin(texteBounds.left + texteBounds.width / 2.0f, texteBounds.top + texteBounds.height / 2.0f);
    m_texte.setPosition(position.x + taille.x / 2.0f, position.y + taille.y / 2.0f);
}

void BoutonAction::dessiner(sf::RenderWindow& window)
{
    window.draw(m_rectangle);
    window.draw(m_texte);
}

bool BoutonAction::estSurvole(const sf::Vector2f& positionSouris)
{
    sf::FloatRect boutonBounds = m_rectangle.getGlobalBounds();
    m_estSurvole = boutonBounds.contains((positionSouris.x), (positionSouris.y));
    if (m_estSurvole)
    {   
        return true;
    }
    else
    {
        return false;
    }
}


bool BoutonAction::aEteClique(const sf::Vector2f& positionSouris)
{   
    
    sf::FloatRect boutonBounds = m_rectangle.getGlobalBounds();
    m_aEteClique = boutonBounds.contains((positionSouris.x), (positionSouris.y));
    if(m_aEteClique) {
        std::cout << "qlf" << std::endl;
        return Invoker::executeCommand(cmd);

    }
    else {
        m_aEteClique = false;
        return false;
    }
}

