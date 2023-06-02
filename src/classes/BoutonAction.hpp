#ifndef BOUTONACTION_HPP
#define BOUTONACTION_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <variant>

#include "Invoker.hpp"
#include "Command.hpp"

class BoutonAction {
public:
    BoutonAction(const std::string& texte, const sf::Vector2f& position, const sf::Vector2f& taille, Invoker& invoker, std::shared_ptr<Command>);

    void dessiner(sf::RenderWindow& window);
    bool estSurvole(const sf::Vector2f& positionSouris);
    bool aEteClique(const sf::Vector2f& positionSouris);
    bool affichable;

private:
    sf::RectangleShape m_rectangle;
    sf::Text m_texte;
    bool m_estSurvole;
    bool m_aEteClique;
    std::shared_ptr<Command> cmd;
};

#endif // BOUTONACTION_HPP
