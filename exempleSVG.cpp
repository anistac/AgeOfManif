#include <SFML/Graphics.hpp>
#include <svgpp/parser/grammar.hpp>
#include <svgpp/adapter/rapidxml/char_traits.hpp>
#include <svgpp/adapter/rapidxml/rapidxml_adapter.hpp>
#include <svgpp/adapter/rapidxml/attribute.hpp>
#include <svgpp/adapter/rapidxml/element_id.hpp>
#include <svgpp/adapter/rapidxml/viewport.hpp>
#include <svgpp/adapter/rapidxml/convert_color.hpp>
#include <svgpp/adapter/rapidxml/convert_lengths.hpp>
#include <svgpp/adapter/rapidxml/convert_transform.hpp>
#include <svgpp/adapter/rapidxml/policy/external_css.hpp>
#include <svgpp/adapter/rapidxml/policy/xml/fwd.hpp>
#include <svgpp/adapter/rapidxml/policy/xml/attribute_parser.hpp>
#include <svgpp/adapter/rapidxml/policy/xml/namespaces.hpp>
#include <svgpp/adapter/rapidxml/policy/xml/filters.hpp>
#include <svgpp/adapter/rapidxml/policy/xml/factory.hpp>
#include <svgpp/adapter/rapidxml/policy/xml/error.hpp>
#include <svgpp/adapter/rapidxml/traits/dimension.hpp>
#include <svgpp/adapter/rapidxml/traits/box.hpp>
#include <svgpp/adapter/rapidxml/traits/viewport.hpp>
#include <svgpp/adapter/rapidxml/traits/gradient.hpp>
#include <svgpp/adapter/rapidxml/traits/length.hpp>
#include <svgpp/adapter/rapidxml/traits/paint.hpp>
#include <svgpp/adapter/rapidxml/traits/path.hpp>
#include <svgpp/adapter/rapidxml/traits/transform.hpp>
#include <svgpp/adapter/rapidxml/traits/color.hpp>

int main()
{
    // Charger le fichier SVG à partir d'un fichier
    rapidxml::xml_document<> doc;
    std::ifstream file("image/map.svg");
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    // Créer un objet SFML Drawable à partir du fichier SVG
    sf::Vector2f size(800, 600);
    sf::RenderTexture renderTexture;
    renderTexture.create(size.x, size.y);
    renderTexture.clear(sf::Color::White);
    svgpp::adapter::rapidxml::document_render<sf::RenderTarget> renderer(renderTexture);
    svgpp::process(doc, renderer);

    // Créer un sprite pour afficher la texture
    sf::Sprite sprite(renderTexture.getTexture());

    // Positionner le sprite à l'endroit souhaité
    sprite.setPosition(0, 0);

    // Afficher le sprite dans une fenêtre
    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "SFML window");
    // ...

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Effacer la fenêtre
        window.clear();

        // Dessiner le sprite sur la fenêtre
        window.draw(sprite);

        // Afficher la fenêtre
        window.display();
    }

    return 0;
}

