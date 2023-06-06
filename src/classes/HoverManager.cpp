#include "HoverManager.hpp"
#include "Grid.hpp"
#include "Region.hpp"
void HoverManager::update() {

  Grid grid = _reg->getGrid();
  Hex hoverredHex = grid.getHoveredHex();
  std::vector<Interactable*> hoverredEntities = hoverredHex.getEntities();
  if(hoverredEntities.size() > 0) {
    for(const auto &entity : hoverredEntities) {
      std::cout << entity->getName() << std::endl;
      std::cout << entity->getCustomName() << std::endl;
      std::cout << entity->getDescription() << std::endl;

    
    }
  }

}
