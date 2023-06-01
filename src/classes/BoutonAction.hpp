#ifndef BOUTONACTION_HPP
#define BOUTONACTION_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <variant>

#include "BoutonAction.hpp"
#include "Invoker.hpp"
#include "Command.hpp"

class BoutonAction {
public:
    using ActionBouton1 = void (BoutonAction::*)();
    using ActionBouton2 = void (BoutonAction::*)();
    BoutonAction(const std::string& texte, const sf::Font& police, const sf::Vector2f& position, const sf::Vector2f& taille, Invoker& invoker, std::shared_ptr<Command>);

    void dessiner(sf::RenderWindow& window);
    bool estSurvole(const sf::Vector2f& positionSouris);
    bool aEteClique(const sf::Vector2f& positionSouris);
    bool affichable;

private:
    std::variant<ActionBouton1, ActionBouton2> m_action;
    sf::RectangleShape m_rectangle;
    sf::Text m_texte;
    bool m_estSurvole;
    bool m_aEteClique;
    std::shared_ptr<Command> cmd;
};

#endif // BOUTONACTION_HPP
