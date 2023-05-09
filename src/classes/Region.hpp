#ifndef REGION_HPP
#define REGION_HPP

//#include "Batiment.hpp"
//#include "Troupe.hpp"
#include "Batiment.hpp"
#include "Troupe.hpp"

#include <string>
#include <vector>

//class Batiment;
//class Troupe;

class Region {
public:
  Region();

private:
  std::string name;
  std::vector<Batiment>  Batiments;
  std::vector<Troupe> Troupes;
  float opinion;
};

#endif // !REGION_HPP


