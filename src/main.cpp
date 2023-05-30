#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
using namespace std;


int main (int argc, char *argv[]) {
  cout << "AOM" << endl;
  Game g;
  g.run();
  return 0;
}
