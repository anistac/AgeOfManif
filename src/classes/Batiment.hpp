#ifndef BATIMENT_HPP
#define BATIMENT_HPP

//#include "Region.hpp"

#include "Interactable.hpp"
#include <string>
 class Region;

class Batiment : public Interactable{
public:
  Batiment();
private:
  std::string nom;
  int camp;
  float sante;
  Region &localisation;
};

#endif // !BATIMENT_HPP

