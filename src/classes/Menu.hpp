#ifndef MENU_HPP
#define MENU_HPP

#include "Win.hpp" // Inclure le fichier d'en-tête correct pour la classe de base
#include <memory>
#include <string>

struct RegionAffichage {
    std::string region;
    std::pair<int, int> position;
};

class Menu : public Win{ // Remplacer "Win" par "Window"
public:
    Menu(sf::RenderWindow &win) {
        _win = &win;
    };
    int checkFont ();
    void makeTick() override; // Retirer le qualificatif "virtual" et corriger l'annotation "override"
    void handleEvent() override;
    void drawMenu(sf::Sprite& sprite, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts, std::vector<RegionAffichage>& regions);

private:
    // Déclarations supplémentaires de membres de classe
    //boutons :)

    std::vector<RegionAffichage> regions;

};

#endif  // MENU_HPP
