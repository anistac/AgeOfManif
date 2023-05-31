#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp> // Include SFML header for sf::RenderWindow
#include <memory>
#include <string>

class Win {
public:
    virtual void makeTick() = 0;

protected:
    sf::RenderWindow window;
};

#endif  // WINDOW_HPP


