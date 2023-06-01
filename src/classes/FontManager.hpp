#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class FontManager {
public:
    static FontManager& getInstance() {
        static FontManager instance;
        return instance;
    }

    sf::Font& getFont() {
        return font;
    }

private:
    FontManager() {
        if (!font.loadFromFile("../assets/arial.ttf")) {
            std::cout << "impossible de charger la police" << std::endl;
        }
    }
    sf::Font font;
};
