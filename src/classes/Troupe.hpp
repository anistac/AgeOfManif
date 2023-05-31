#ifndef TROUPE_HPP
#define TROUPE_HPP

#include "Hex.hpp"
#include <SFML/System/String.hpp>
#include "Region.hpp"

class Troupe : public Interactable {
public:
  Troupe(): _region(Region()), _name("Troupe"), _camp(0), _moral(100) {
  };
  Troupe(std::string name, int camp, Region &region, float moral)
    : _name(name), _camp(camp), _region(region), _moral(moral) {};
  virtual ~Troupe() {};
protected:
  std::string _name;
  int _camp;
  Region _region;
  float _moral;
};

#endif // !TROUPE_HPP
