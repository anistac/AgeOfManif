#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp> // Include SFML header for sf::RenderWindow
#include <memory>
#include <string>

class Win {
public:
    virtual void makeTick() = 0;
    void setWindow(sf::RenderWindow &win) {
        _win = &win;
    }
    virtual void handleEvent() = 0;
    // static void setSelectedWin(int i) {
    //     _selectedWin = i;
    // }
    // static int getSelectedWin() {
    //     return _selectedWin;
    // }

    static int selectedWin;
protected:
    sf::RenderWindow* _win;
};

#endif  // WINDOW_HPP


