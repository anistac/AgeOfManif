#ifndef BOUTONACTION_HPP
#define BOUTONACTION_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <variant>

class BoutonAction {
public:
    using ActionBouton1 = void (BoutonAction::*)();
    using ActionBouton2 = void (BoutonAction::*)();
    BoutonAction(const std::string& texte, const sf::Font& police, const sf::Vector2f& position, const sf::Vector2f& taille);

    void dessiner(sf::RenderWindow& window);
    bool estSurvole(const sf::Vector2i& positionSouris);
    bool aEteClique() const;
    void executerAction(/*Command*/);

private:
    std::variant<ActionBouton1, ActionBouton2> m_action;
    sf::RectangleShape m_rectangle;
    sf::Text m_texte;
    bool m_estSurvole;
    bool m_aEteClique;
};

#endif // BOUTONACTION_HPP
