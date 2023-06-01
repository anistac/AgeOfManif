#include <iostream>
#include "Menu.hpp"
#include "Win.hpp"
#include <SFML/Graphics.hpp>

sf::Font font; // Déclaration de la variable font

int checkFont (){
    // Créer une police (chargement d'un fichier de police TrueType)
	if (!font.loadFromFile("../assets/arial.ttf"))
	{
		// erreur : impossible de charger la police
		return -1;
	}
}



// drawMenu(sf::Sprite& sprite, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts, std::vector<RegionAffichage>& regions)
// {
//     _win->clear(sf::Color::White);
//     _win->draw(sprite);
//     for (const auto& button : buttons)
//     {
//         _win->draw(button);
//     }
    
//     for (const auto& buttonText : buttonTexts)
//     {
//         _win->draw(buttonText);
//     }
    
//     for (auto it = regions.begin(); it != regions.end(); ++it)
//     {
//         sf::Text temp;
//         temp.setFont(font);
//         temp.setString(it->region);
//         temp.setCharacterSize(20);
//         temp.setFillColor(sf::Color::Black);
//         temp.setPosition(it->position.first, it->position.second);
//         _win->draw(temp);
//     }
//     _win->display();


// }

void Menu::handleEvent() {
    std::cout << "event" << std::endl;
}

void Menu::makeTick(){

    // Charger l'image de fond à partir d'un fichier
    sf::Texture backgroundImage;
    if(!backgroundImage.loadFromFile("../assets/carteDeFrance.png")) {
        throw std::runtime_error("impossible de charger la carte mskn");
    }
    sf::Sprite sprite(backgroundImage);
    // Créer un texte
	sf::Text text;
	text.setFont(font); // définir la police
	//text.setString("Bonjour, monde !"); // définir le texte à afficher
	text.setCharacterSize(24); // définir la taille des caractères (en points)
	text.setFillColor(sf::Color::White); // définir la couleur de remplissage
	text.setPosition(100, 100); // définir la position du texte dans la fenêtre

    std::vector<RegionAffichage> regions;
    // Ajouter des éléments à la structure regions : Affichage des nom des régions sur la carte
    regions.push_back({"Ile De France", {400, 210}});
    regions.push_back({"Vendee", {220, 320}});
    regions.push_back({"Normandie", {260, 200}});
    regions.push_back({"Bretagne", {100, 270}});
    regions.push_back({"Grand Est", {600, 210}});
    regions.push_back({"Grand Nord", {430, 90}});
    regions.push_back({"Bourgogne", {550, 350}});
    regions.push_back({"Val-de-Loire", {350, 330}});
    regions.push_back({"Aquitaine", {300, 500}});
    regions.push_back({"Rhone-Alpes", {500, 520}});
    regions.push_back({"Region Paca", {630, 650}});
    regions.push_back({"Occitanie",{400, 650}});
    
    std::vector<sf::Text> regionTexts;
    for (auto it = regions.begin(); it != regions.end(); ++it) {
        sf::Text texte;
        texte.setFont(font);
        texte.setString(it->region);
        texte.setCharacterSize(20);
        texte.setFillColor(sf::Color::Black);
        texte.setPosition(it->position.first, it->position.second);
        regionTexts.push_back(texte);
    }

    // Créer les texte s : titre des régions
    std::vector<std::string> regionNames = { "Ile De France", "Vendee", "Normandie", "Bretagne", "Grand Est", "Grand Nord", "Bourgogne", "Val-de-Loire", "Aquitaine", "Rhone-Alpes", "Region Paca", "Occitanie" };
    std::vector<std::pair<int, int>> mousePositions;
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;

    float buttonX = 30.0f;
    float buttonY = 30.0f;
    float buttonSpacing = 40.0f;
    int iterator = 1;

    for (const auto& regionName : regionNames)
    {
        sf::RectangleShape button(sf::Vector2f(150, 30));
        button.setFillColor(sf::Color::Black);
        button.setPosition(buttonX, buttonY);

        sf::Text buttonText;
        buttonText.setFont(font);
        buttonText.setString(regionName);
        buttonText.setCharacterSize(20);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(buttonX, buttonY);
        mousePositions.push_back(std::make_pair(buttonX, buttonY));

        buttons.push_back(button);
        buttonTexts.push_back(buttonText);

        iterator += 1;
        if (iterator == 5)  buttonY += 220;
        buttonY += buttonSpacing;
        
    }
    int buttonPressed;
    // Gérer les événements
    sf::Event event;
    while (_win->pollEvent(event))
    {
        // Fermer la fenêtre si l'utilisateur clique sur la croix en haut à droite
        // Si l'utilisateur clique sur le bouton gauche de la souris
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {   
            // Mettre à jour la position de la souris
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*_win);

            for (int i = 0; i < buttons.size(); ++i) {
                const auto& button = buttons[i];
                if (sf::Mouse::getPosition(*_win).x >= button.getPosition().x &&
                    sf::Mouse::getPosition(*_win).x <= button.getPosition().x + button.getSize().x &&
                    sf::Mouse::getPosition(*_win).y >= button.getPosition().y &&
                    sf::Mouse::getPosition(*_win).y <= button.getPosition().y + button.getSize().y)
                {
                    buttonPressed = i;
                    Menu::selectedWin = 1; // Repasse sur le showMain
                    text.setString(regionNames[buttonPressed]); // définir le texte à afficher
                }
            }   
        }
    } 
       
    _win->clear(sf::Color::White);
    _win->draw(sprite);
    for (const auto& button : buttons)
    {
        _win->draw(button);
    }
    
    for (const auto& buttonText : buttonTexts)
    {
        _win->draw(buttonText);
    }
    
    for (auto it = regions.begin(); it != regions.end(); ++it)
    {
        sf::Text temp;
        temp.setFont(font);
        temp.setString(it->region);
        temp.setCharacterSize(20);
        temp.setFillColor(sf::Color::Black);
        temp.setPosition(it->position.first, it->position.second);
        _win->draw(temp);
    }
    _win->display();   
}