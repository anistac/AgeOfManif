#include <SFML/Graphics.hpp>
#include <iostream>

// Fonction pour vérifier si un point se trouve à l'intérieur d'un contour
bool isPointInsideContour(const std::vector<sf::Vector2f>& contour, const sf::Vector2f& point)
{
    int intersectCount = 0;
    sf::Vector2f p1, p2;

    int n = contour.size();
    for (int i = 0; i < n; ++i)
    {
        p1 = contour[i];
        p2 = contour[(i + 1) % n];

        if (point.y > std::min(p1.y, p2.y))
        {
            if (point.y <= std::max(p1.y, p2.y))
            {
                if (point.x <= std::max(p1.x, p2.x))
                {
                    if (p1.y != p2.y)
                    {
                        float xinters = (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
                        if (p1.x == p2.x || point.x <= xinters)
                            intersectCount++;
                    }
                }
            }
        }
    }

    return (intersectCount % 2 != 0);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Détection de contour");

    sf::Texture texture;
    if (!texture.loadFromFile("image/map.png")) // Remplacez "image.png" par le chemin de votre image PNG
    {
        std::cout << "Erreur : Impossible de charger l'image PNG." << std::endl;
        return 1;
    }

    sf::Sprite sprite(texture);

    // Définir les coordonnées des contours (à partir de votre image SVG)
    std::vector<sf::Vector2f> contour;
    // Ajoutez les coordonnées des points du contour ici

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                // Vérifier si le point cliqué se trouve à l'intérieur du contour
                bool isInsideContour = isPointInsideContour(contour, mousePosition);

                if (isInsideContour)
                    std::cout << "Le point se trouve à l'intérieur du contour." << std::endl;
                else
                    std::cout << "Le point se trouve à l'extérieur du contour." << std::endl;
            }
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}

