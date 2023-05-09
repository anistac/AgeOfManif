#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


int main (int argc, char *argv[]) {
  cout << "AOM" << endl;
  sf::RenderWindow win(sf::VideoMode(640, 480), "win");
  while (win.isOpen()) {
    sf::Event e;
    while (win.pollEvent(e)) {
      if(e.type == sf::Event::Closed) win.close();
    }
    win.clear();
    win.display();
  }
  return 0;
}
