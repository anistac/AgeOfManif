#ifndef PAYS_HPP
#define PAYS_HPP

#include "Region.hpp"
#include <array>
#include <map>
#include <string>
#include <vector>
class Pays {
public:
  Pays();

private:
  std::vector<Region> Regions;
  std::map<int, std::string> camps;
};

#endif // !PAYS_HPP
