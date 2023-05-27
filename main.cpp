#include "window.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void draw(sf::RenderWindow& window, sf::Sprite& sprite, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts, std::vector<sf::Text>& regionTexts)
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
    
    for (const auto& regionText : regionTexts)
    {
        window.draw(regionText);
    }
    window.display();
}


int main() {

    // Charger l'image de fond à partir d'un fichier
    sf::Image backgroundImage;
    if (!backgroundImage.loadFromFile("image/map.png"))
    {
        // Erreur : Impossible de charger l'image de fond
        return 1;
    }
    

    // Créer une nouvelle image avec la même taille que l'image de fond
    sf::Image newImage;
    newImage.create(backgroundImage.getSize().x, backgroundImage.getSize().y, sf::Color::Transparent);

    // Créer une texture à partir de la nouvelle image
    sf::Texture texture;
    texture.loadFromImage(newImage);

    // Créer un sprite pour afficher la texture
    sf::Sprite sprite(texture);

    // Positionner le sprite à l'endroit souhaité
    sprite.setPosition(0, 0);

    // Afficher le sprite dans une fenêtre
    sf::RenderWindow window(sf::VideoMode(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height), "Edge of Manifs");
    
    //___________________________________________________________________________________________________
    
    // Créer une police (chargement d'un fichier de police TrueType)
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// erreur : impossible de charger la police
		return -1;
	}
    
    // Créer un texte
	sf::Text text;
	text.setFont(font); // définir la police
	text.setString("Bonjour, monde !"); // définir le texte à afficher
	text.setCharacterSize(24); // définir la taille des caractères (en points)
	text.setFillColor(sf::Color::White); // définir la couleur de remplissage
	text.setPosition(100, 100); // définir la position du texte dans la fenêtre
	
	// Créer les textes : titre des régions

    
    std::vector<std::string> nomsDesRegions = {
        "Ile De France",
        "Vendee",
        "Normandie",
        "Bretagne",
        "Grand Est",
        "Grand Nord",
        "Bourgogne",
        "Val-de-Loire",
        "Aquitaine",
        "Rhone-Alpes",
        "Region Paca",
        "Val-de-Loire"
    };
    

    /*
	sf::Text texteIledeFrance;
    texteIledeFrance.setFont(font);
    texteIledeFrance.setString("Ile De France");
    texteIledeFrance.setCharacterSize(20);
    texteIledeFrance.setFillColor(sf::Color::Black);
    texteIledeFrance.setPosition(400, 210);
    
	
	sf::Text texteVendee;
    texteVendee.setFont(font);
    texteVendee.setString("Vendee");
    texteVendee.setCharacterSize(20);
    texteVendee.setFillColor(sf::Color::Black);
    texteVendee.setPosition(220, 320);
    
        sf::Text texteNormandie;
    texteNormandie.setFont(font);
    texteNormandie.setString("Normandie");
    texteNormandie.setCharacterSize(20);
    texteNormandie.setFillColor(sf::Color::Black);
    texteNormandie.setPosition(260, 200);
    
    sf::Text texteBretagne;
    texteBretagne.setFont(font);
    texteBretagne.setString("Bretagne");
    texteBretagne.setCharacterSize(20);
    texteBretagne.setFillColor(sf::Color::Black);
    texteBretagne.setPosition(100, 270);
    
    sf::Text texteGrandEst;
    texteGrandEst.setFont(font);
    texteGrandEst.setString("Grand Est");
    texteGrandEst.setCharacterSize(20);
    texteGrandEst.setFillColor(sf::Color::Black);
    texteGrandEst.setPosition(600, 210);
    
    sf::Text texteGrandNord;
    texteGrandNord.setFont(font);
    texteGrandNord.setString("Grand Nord");
    texteGrandNord.setCharacterSize(20);
    texteGrandNord.setFillColor(sf::Color::Black);
    texteGrandNord.setPosition(430, 90);
    
    sf::Text texteBourgogne;
    texteBourgogne.setFont(font);
    texteBourgogne.setString("Bourgogne");
    texteBourgogne.setCharacterSize(20);
    texteBourgogne.setFillColor(sf::Color::Black);
    texteBourgogne.setPosition(550, 350);
    
    sf::Text texteValdeLoir;
    texteValdeLoir.setFont(font);
    texteValdeLoir.setString("Val-de-Loire");
    texteValdeLoir.setCharacterSize(20);
    texteValdeLoir.setFillColor(sf::Color::Black);
    texteValdeLoir.setPosition(350, 330);
    
    sf::Text texteAquitaine;
    texteAquitaine.setFont(font);
    texteAquitaine.setString("Aquitaine");
    texteAquitaine.setCharacterSize(20);
    texteAquitaine.setFillColor(sf::Color::Black);
    texteAquitaine.setPosition(300, 500);
    
    sf::Text texteRhoneAlpes;
    texteRhoneAlpes.setFont(font);
    texteRhoneAlpes.setString("Rhone-Alpes");
    texteRhoneAlpes.setCharacterSize(20);
    texteRhoneAlpes.setFillColor(sf::Color::Black);
    texteRhoneAlpes.setPosition(500, 520);
    
    sf::Text textePaca;
    textePaca.setFont(font);
    textePaca.setString("Region Paca");
    textePaca.setCharacterSize(20);
    textePaca.setFillColor(sf::Color::Black);
    textePaca.setPosition(630, 650);
    
    sf::Text texteOcciatanie;
    texteOcciatanie.setFont(font);
    texteOcciatanie.setString("Occitanie");
    texteOcciatanie.setCharacterSize(20);
    texteOcciatanie.setFillColor(sf::Color::Black);
    texteOcciatanie.setPosition(400, 650);

    */
    
    
	// Créer un boutton
    sf::RectangleShape button(sf::Vector2f(150, 30));
    button.setFillColor(sf::Color::Blue);
    button.setPosition(30, 30);
    
    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("Ile De France");
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(button.getPosition().x + (button.getSize().x - buttonText.getGlobalBounds().width) / 2, button.getPosition().y + (button.getSize().y - buttonText.getGlobalBounds().height) / 2);
    
    // Créer un 2eme boutton
    sf::RectangleShape button1(sf::Vector2f(150, 30));
    button1.setFillColor(sf::Color::Black);
    button1.setPosition(30, 70);
    
    sf::Text buttonText1;
    buttonText1.setFont(font);
    buttonText1.setString("Vendee");
    buttonText1.setCharacterSize(20);
    buttonText1.setFillColor(sf::Color::White);
    buttonText1.setPosition(button1.getPosition().x + (button1.getSize().x - buttonText1.getGlobalBounds().width) / 2, button1.getPosition().y + (button1.getSize().y - buttonText1.getGlobalBounds().height) / 2);

	// Créer un 3eme boutton
    sf::RectangleShape button2(sf::Vector2f(150, 30));
    button2.setFillColor(sf::Color::Black);
    button2.setPosition(30, 110);
    
    sf::Text buttonText2;
    buttonText2.setFont(font);
    buttonText2.setString("Bretagne");
    buttonText2.setCharacterSize(20);
    buttonText2.setFillColor(sf::Color::White);
    buttonText2.setPosition(button2.getPosition().x + (button2.getSize().x - buttonText2.getGlobalBounds().width) / 2, button2.getPosition().y + (button2.getSize().y - buttonText2.getGlobalBounds().height) / 2);
    
    // Créer un 4eme boutton
    sf::RectangleShape button3(sf::Vector2f(150, 30));
    button3.setFillColor(sf::Color::Black);
    button3.setPosition(30, 150);
    
    sf::Text buttonText3;
    buttonText3.setFont(font);
    buttonText3.setString("Normandie");
    buttonText3.setCharacterSize(20);
    buttonText3.setFillColor(sf::Color::White);
    buttonText3.setPosition(button3.getPosition().x + (button3.getSize().x - buttonText3.getGlobalBounds().width) / 2, button3.getPosition().y + (button3.getSize().y - buttonText3.getGlobalBounds().height) / 2);
    
    // Créer un 5eme boutton
    sf::RectangleShape button4(sf::Vector2f(150, 30));
    button4.setFillColor(sf::Color::Black);
    button4.setPosition(30, 370);
    
    sf::Text buttonText4;
    buttonText4.setFont(font);
    buttonText4.setString("Grand Est");
    buttonText4.setCharacterSize(20);
    buttonText4.setFillColor(sf::Color::White);
    buttonText4.setPosition(button4.getPosition().x + (button4.getSize().x - buttonText4.getGlobalBounds().width) / 2, button4.getPosition().y + (button4.getSize().y - buttonText4.getGlobalBounds().height) / 2);
    
    // Créer un 6eme boutton
    sf::RectangleShape button5(sf::Vector2f(150, 30));
    button5.setFillColor(sf::Color::Black);
    button5.setPosition(30, 410);
    
    sf::Text buttonText5;
    buttonText5.setFont(font);
    buttonText5.setString("Grand Nord");
    buttonText5.setCharacterSize(20);
    buttonText5.setFillColor(sf::Color::White);
    buttonText5.setPosition(button5.getPosition().x + (button5.getSize().x - buttonText5.getGlobalBounds().width) / 2, button5.getPosition().y + (button5.getSize().y - buttonText5.getGlobalBounds().height) / 2);

	// Créer un 7eme boutton
    sf::RectangleShape button6(sf::Vector2f(150, 30));
    button6.setFillColor(sf::Color::Black);
    button6.setPosition(30, 450);
    
    sf::Text buttonText6;
    buttonText6.setFont(font);
    buttonText6.setString("Paca");
    buttonText6.setCharacterSize(20);
    buttonText6.setFillColor(sf::Color::White);
    buttonText6.setPosition(button6.getPosition().x + (button6.getSize().x - buttonText6.getGlobalBounds().width) / 2, button6.getPosition().y + (button6.getSize().y - buttonText6.getGlobalBounds().height) / 2);
    
    // Créer un 8eme boutton
    sf::RectangleShape button7(sf::Vector2f(150, 30));
    button7.setFillColor(sf::Color::Black);
    button7.setPosition(30, 490);
    
    sf::Text buttonText7;
    buttonText7.setFont(font);
    buttonText7.setString("Aquitaine");
    buttonText7.setCharacterSize(20);
    buttonText7.setFillColor(sf::Color::White);
    buttonText7.setPosition(button7.getPosition().x + (button7.getSize().x - buttonText7.getGlobalBounds().width) / 2, button7.getPosition().y + (button7.getSize().y - buttonText7.getGlobalBounds().height) / 2);
    
    // Créer un 9eme boutton
    sf::RectangleShape button8(sf::Vector2f(150, 30));
    button8.setFillColor(sf::Color::Black);
    button8.setPosition(30, 530);
    
    sf::Text buttonText8;
    buttonText8.setFont(font);
    buttonText8.setString("Occitanie");
    buttonText8.setCharacterSize(20);
    buttonText8.setFillColor(sf::Color::White);
    buttonText8.setPosition(button8.getPosition().x + (button8.getSize().x - buttonText8.getGlobalBounds().width) / 2, button8.getPosition().y + (button8.getSize().y - buttonText8.getGlobalBounds().height) / 2);
    
    // Créer un 10eme boutton
    sf::RectangleShape button9(sf::Vector2f(150, 30));
    button9.setFillColor(sf::Color::Black);
    button9.setPosition(30, 570);
    
    sf::Text buttonText9;
    buttonText9.setFont(font);
    buttonText9.setString("Rhone-Alpes");
    buttonText9.setCharacterSize(20);
    buttonText9.setFillColor(sf::Color::White);
    buttonText9.setPosition(button9.getPosition().x + (button9.getSize().x - buttonText9.getGlobalBounds().width) / 2, button9.getPosition().y + (button9.getSize().y - buttonText9.getGlobalBounds().height) / 2);
    
    // Créer un 11eme boutton
    sf::RectangleShape button10(sf::Vector2f(150, 30));
    button10.setFillColor(sf::Color::Black);
    button10.setPosition(30, 610);
    
    sf::Text buttonText10;
    buttonText10.setFont(font);
    buttonText10.setString("Bourgogne");
    buttonText10.setCharacterSize(20);
    buttonText10.setFillColor(sf::Color::White);
    buttonText10.setPosition(button10.getPosition().x + (button10.getSize().x - buttonText10.getGlobalBounds().width) / 2, button10.getPosition().y + (button10.getSize().y - buttonText10.getGlobalBounds().height) / 2);
    
    // Créer un 12eme boutton
    sf::RectangleShape button11(sf::Vector2f(150, 30));
    button11.setFillColor(sf::Color::Black);
    button11.setPosition(30, 650);
    
    sf::Text buttonText11;
    buttonText11.setFont(font);
    buttonText11.setString("Val-de-Loire");
    buttonText11.setCharacterSize(20);
    buttonText11.setFillColor(sf::Color::White);
    buttonText11.setPosition(button11.getPosition().x + (button11.getSize().x - buttonText11.getGlobalBounds().width) / 2, button11.getPosition().y + (button11.getSize().y - buttonText11.getGlobalBounds().height) / 2);
    
   for (const auto& nom : nomsDesRegions) {
        sf::Text texte;
        texte.setFont(font);
        texte.setString(nomRegion);
        texte.setCharacterSize(20);
        texte.setFillColor(sf::Color::Blue);
        regionTexts.push_back(texte);
    }

	// Recapituler ensemble pour faciliter la lecture du code 
	
	std::vector<sf::RectangleShape> buttons;
	buttons.push_back(button);
	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
	buttons.push_back(button4);
	buttons.push_back(button5);
	buttons.push_back(button6);
	buttons.push_back(button7);
	buttons.push_back(button8);
	buttons.push_back(button9);
	buttons.push_back(button10);
	buttons.push_back(button11);

	std::vector<sf::Text> buttonTexts;
	buttonTexts.push_back(buttonText);
	buttonTexts.push_back(buttonText1);
	buttonTexts.push_back(buttonText2);
	buttonTexts.push_back(buttonText3);
	buttonTexts.push_back(buttonText4);
	buttonTexts.push_back(buttonText5);
	buttonTexts.push_back(buttonText6);
	buttonTexts.push_back(buttonText7);
	buttonTexts.push_back(buttonText8);
	buttonTexts.push_back(buttonText9);
	buttonTexts.push_back(buttonText10);
	buttonTexts.push_back(buttonText11);

	std::vector<sf::Text> regionTexts;
	regionTexts.push_back(texteIledeFrance);
	regionTexts.push_back(texteVendee);
	regionTexts.push_back(texteBretagne);
	regionTexts.push_back(texteNormandie);
	regionTexts.push_back(texteGrandEst);
	regionTexts.push_back(texteGrandNord);
	regionTexts.push_back(texteBourgogne);
	regionTexts.push_back(texteValdeLoir);
	regionTexts.push_back(texteAquitaine);
	regionTexts.push_back(texteRhoneAlpes);
	regionTexts.push_back(textePaca);
	regionTexts.push_back(texteOcciatanie);


   
    
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
            	//_______________________________________________________Fenetre Ile De France_____________________________________________________________________
            	
                // Si le clic est dans une zone précise de la fenêtre (ici, boutton Ile de France)
                if (event.mouseButton.x >= button.getPosition().x && event.mouseButton.x <= button.getPosition().x + button.getSize().x && event.mouseButton.y >= button.getPosition().y && event.mouseButton.y <= button.getPosition().y + button.getSize().y)
				{
		            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		            sf::Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

		            	
		            // Le bouton a été cliqué
		            std::cout << "Ile De France" << std::endl;
		            	
		            // Créer une nouvelle fenêtre
		            sf::RenderWindow subWindow(sf::VideoMode(600, 600), "Ile De France");

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
                        }
                        // Effacer le contenu de la sous-fenêtre
		                subWindow.clear();
						
						// Dessiner le texte
    					subWindow.draw(text);
    						
		                // Afficher le contenu de la sous-fenêtre
		                subWindow.display();
                    }
                }
                        }
        }        
        
       draw(window, sprite, buttons, buttonTexts, regionTexts);
        

        // Mettre à jour la fenêtre
        window.display();
    }

    return 0;
}
