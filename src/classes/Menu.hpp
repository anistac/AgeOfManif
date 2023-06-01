#ifndef MENU_HPP
#define MENU_HPP

#include "Win.hpp" // Inclure le fichier d'en-tête correct pour la classe de base
#include <memory>
#include <string>
#include <vector>

struct RegionAffichage {
    std::string region;
    std::pair<int, int> position;
};

class Menu : public Win{ // Remplacer "Win" par "Window"
public:
    Menu(sf::RenderWindow &win);
    void makeTick() override; // Retirer le qualificatif "virtual" et corriger l'annotation "override"
    void handleEvent(sf::Event event) override;
    
private:
    // Déclarations supplémentaires de membres de classe
    //boutons :)

    std::vector<RegionAffichage> regions;
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;
    std::vector<std::pair<int, int>> mousePositions;
    sf::Sprite _sprite;
    sf::Texture backgroundImage;
   

};

#endif  // MENU_HPP
