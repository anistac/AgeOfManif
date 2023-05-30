#include "classes/BoutonAction.hpp"
#include "classes/InfoGame.hpp"
#include "classes/Manifester.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

sf::Font font; // Déclaration de la variable font

struct Region {
        std::string region;
        std::pair<int, int> position;
    };
    std::vector<Region> regions;

void draw(sf::RenderWindow& window, sf::Sprite& sprite, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts, std::vector<Region>& regions)
{
    window.clear(sf::Color::White);
    window.draw(sprite);
    for (const auto& button : buttons)
    {
        window.draw(button);
    }
    
    for (const auto& buttonText : buttonTexts)
    {
        window.draw(buttonText);
    }
    
    for (auto it = regions.begin(); it != regions.end(); ++it)
    {
        sf::Text temp;
        temp.setFont(font);
        temp.setString(it->region);
        temp.setCharacterSize(20);
        temp.setFillColor(sf::Color::Black);
        temp.setPosition(it->position.first, it->position.second);
        window.draw(temp);
    }
    window.display();
}

int main()
{
    // Créer une police (chargement d'un fichier de police TrueType)
	if (!font.loadFromFile("../assets/arial.ttf"))
	{
		// erreur : impossible de charger la police
		return -1;
	}

    // Charger l'image de fond à partir d'un fichier
    sf::Image backgroundImage;
    if (!backgroundImage.loadFromFile("image/map.png"))
    {
        // Erreur : Impossible de charger l'image de fond
        return 1;
    }

    // Créer une texture à partir de la nouvelle image
    sf::Texture texture;
    texture.loadFromImage(backgroundImage);

    // Créer un sprite pour afficher la texture
    sf::Sprite sprite(texture);

    // Positionner le sprite à l'endroit souhaité
    sprite.setPosition(0, 0);

    // Afficher le sprite dans une fenêtre
    sf::RenderWindow window(sf::VideoMode(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height), "Age of Manifs");
    //___________________________________________________________________________________________________
    
    // Créer un texte
	sf::Text text;
	text.setFont(font); // définir la police
	text.setString("Bonjour, monde !"); // définir le texte à afficher
	text.setCharacterSize(24); // définir la taille des caractères (en points)
	text.setFillColor(sf::Color::White); // définir la couleur de remplissage
	text.setPosition(100, 100); // définir la position du texte dans la fenêtre

    // Créer une police (chargement d'un fichier de police TrueType)
	sf::Font font;
	if (!font.loadFromFile("../assets/arial.ttf"))
	{
		// erreur : impossible de charger la police
		return -1;
	}

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

    // Créer les textes : titre des régions
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
    // Créer le rectangle blanc
    sf::RectangleShape menuBackground(sf::Vector2f(400, 200));
    menuBackground.setPosition(400,600);

    // Créer le texte "Actions :"
    sf::Text titleText("Actions :", font, 18);
    titleText.setPosition(400, 600);
    titleText.setFillColor(sf::Color::Black);

    Invoker invoker;
    //std::shared_ptr<Command> manifesterCommand = std::make_unique<Manifester>();
    //BoutonAction bouton("Texte", police, position, taille, invoker, std::move(manifesterCommand));

    Manifester *manifesterCommand = new Manifester;
    // std::shared_ptr<Manifester> pManifesterCmd = std::make_unique<Manifester> (manifesterCommand); 
    std::shared_ptr<Command> cmd(manifesterCommand);
    BoutonAction bouton1("Action 1", font, sf::Vector2f(610, 675), sf::Vector2f(50, 50), invoker, cmd);
    //BoutonAction bouton2("Action 2", font, sf::Vector2f(670, 675), sf::Vector2f(50, 50));
    //BoutonAction bouton3("Action 3", font, sf::Vector2f(730, 675), sf::Vector2f(50, 50));

    // Créer le rectangle blanc Bar haute
    sf::RectangleShape barAffichage(sf::Vector2f(800, 40));
    barAffichage.setPosition(0,0);

    InfoGame barGame(font);
    int opinion = 65;
    int argent = 15600;

   int buttonPressed;
    while (window.isOpen())
    {
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Fermer la fenêtre si l'utilisateur clique sur la croix en haut à droite
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Si l'utilisateur clique sur le bouton gauche de la souris
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                for (int i = 0; i < buttons.size(); ++i) {
                    const auto& button = buttons[i];
                    if (sf::Mouse::getPosition(window).x >= button.getPosition().x &&
                        sf::Mouse::getPosition(window).x <= button.getPosition().x + button.getSize().x &&
                        sf::Mouse::getPosition(window).y >= button.getPosition().y &&
                        sf::Mouse::getPosition(window).y <= button.getPosition().y + button.getSize().y)
                    {
                        buttonPressed = i;
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        
                            
                        // Créer une nouvelle fenêtre
                        sf::RenderWindow subWindow(sf::VideoMode(800, 800), regionNames[buttonPressed]);

                        // Boucle de la sous-fenêtre
                        while (subWindow.isOpen())
                        {
                            // Gérer les événements de la sous-fenêtre
                            sf::Event subEvent;
                            while (subWindow.pollEvent(subEvent))
                            {
                                // Fermer la sous-fenêtre si l'utilisateur clique sur la croix en haut à droite
                                if (subEvent.type == sf::Event::Closed)
                                {
                                    subWindow.close();
                                }
                                
                                // Mettre à jour la position de la souris
                                sf::Vector2i mousePosition = sf::Mouse::getPosition(subWindow);

                                if(subEvent.type == sf::Event::MouseMoved)  {
                                    bouton1.estSurvole(sf::Vector2f(subEvent.mouseMove.x, subEvent.mouseMove.y));
                                    
                                }
                                if(subEvent.type == sf::Event::MouseButtonPressed) {
                                    sf::Vector2i mp = sf::Mouse::getPosition(subWindow);
                                    bouton1.aEteClique(sf::Vector2f(mp.x, mp.y));
                                }
                            }
                            // Effacer le contenu de la sous-fenêtre
                            subWindow.clear();
                                
                            // Dessiner le texte
                            barGame.dessiner(subWindow, opinion, argent);
                            subWindow.draw(text);
                            subWindow.draw(menuBackground);
                            subWindow.draw(titleText);
                                
                            // Dessiner les boutons d'action
                            bouton1.dessiner(subWindow);
                            //bouton2.dessiner(subWindow);
                            //bouton3.dessiner(subWindow);

                            // Afficher le contenu de la sous-fenêtre
                            subWindow.display();
                        }
                    }
                }
            }
        }            
        
        draw(window, sprite, buttons, buttonTexts, regions);

        // Mettre à jour la fenêtre
        window.display();
    }
    
    return 0;
}