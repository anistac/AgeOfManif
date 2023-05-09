#ifndef TROUPE_HPP
#define TROUPE_HPP

#include <SFML/System/String.hpp>
class Region;

class Troupe {
public:
  Troupe();
private:
  std::string nom;
  int camp;
  Region &localisation;
  float moral;
};

#endif // !TROUPE_HPP
