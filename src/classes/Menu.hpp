#ifndef MENU_HPP
#define MENU_HPP

#include "Win.hpp" // Inclure le fichier d'en-tête correct pour la classe de base
#include <memory>
#include <string>

class Menu : public Win{ // Remplacer "Win" par "Window"
public:
    Menu(sf::RenderWindow &win) {
        _win = &win;
    };
    void makeTick() override; // Retirer le qualificatif "virtual" et corriger l'annotation "override"

private:
    // Déclarations supplémentaires de membres de classe
};

#endif  // MENU_HPP
