#ifndef BOUTONACTION_HPP
#define BOUTONACTION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <functional>
#include <variant>

#include "Invoker.hpp"
#include "Command.hpp"
#include "ActionType.hpp"

class BoutonAction : public sf::Drawable {
public:
    BoutonAction(const std::string& texte, const sf::Vector2f& position, const sf::Vector2f& taille, Action action);

    bool estSurvole(const sf::Vector2i& positionSouris);
    bool aEteClique(const sf::Vector2i& positionSouris);
    bool affichable;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    // void setPosition(const sf::Vector2f& position) { this->setPosition(position); }
private:
    sf::RectangleShape m_rectangle;
    sf::Text m_texte;
    bool m_estSurvole;
    bool m_aEteClique;
    Action _action;
};

#endif // BOUTONACTION_HPP
