#include <SFML/Graphics.hpp>

int main()
{
    // Charger l'image de fond à partir d'un fichier
    sf::Image backgroundImage;
    if (!backgroundImage.loadFromFile("background.png"))
    {
        // Erreur : Impossible de charger l'image de fond
        return 1;
    }

    // Charger l'image à afficher par-dessus à partir d'un fichier
    sf::Image overlayImage;
    if (!overlayImage.loadFromFile("overlay.png"))
    {
        // Erreur : Impossible de charger l'image à afficher par-dessus
        return 1;
    }

    // Créer une nouvelle image avec la même taille que l'image de fond
    sf::Image newImage;
    newImage.create(backgroundImage.getSize().x, backgroundImage.getSize().y, sf::Color::Transparent);

    // Copier les pixels de l'image de fond sur la nouvelle image en remplaçant les pixels transparents par les pixels correspondants de l'autre image
    for (unsigned int x = 0; x < backgroundImage.getSize().x; x++)
    {
        for (unsigned int y = 0; y < backgroundImage.getSize().y; y++)
        {
            sf::Color pixelColor = backgroundImage.getPixel(x, y);
            if (pixelColor.a == 0)
            {
                newImage.setPixel(x, y, overlayImage.getPixel(x, y));
            }
            else
            {
                newImage.setPixel(x, y, pixelColor);
            }
        }
    }

    // Créer une texture à partir de la nouvelle image
    sf::Texture texture;
    texture.loadFromImage(newImage);

    // Créer un sprite pour afficher la texture
    sf::Sprite sprite(texture);

    // Positionner le sprite à l'endroit souhaité
    sprite.setPosition(0, 0);

    // Afficher le sprite dans une fenêtre
    sf::RenderWindow window(sf::VideoMode(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height), "Edge of Manifs");

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
                // Si le clic est dans une zone précise de la fenêtre
                 // Si le clic est dans une zone précise de la fenêtre (ici, en haut à gauche)
                if (event.mouseButton.x < 100 && event.mouseButton.y < 100)
                {
                    // Créer une nouvelle fenêtre
                    sf::RenderWindow subWindow(sf::VideoMode(400, 300), "Actions");

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

                        // Afficher le contenu de la sous-fenêtre
                        subWindow.display();
                    }
                }
            }
        }
        

        // Effacer la fenêtre avec une couleur de fond
        window.clear(sf::Color::White);

        // Dessiner le sprite
        window.draw(sprite);

        // Mettre à jour la fenêtre
        window.display();
    }

    return 0;
}

