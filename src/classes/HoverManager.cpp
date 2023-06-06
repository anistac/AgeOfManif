#include "HoverManager.hpp"
#include "Grid.hpp"
#include "FontManager.hpp"
#include "Region.hpp"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#define BAR_WIDTH 450
#define BAR_HEIGHT 200
#define MARGIN 10
#define PADDING 5
void HoverManager::update() {
  _infos.clear();
  Grid grid = _reg->getGrid();
  Hex hoverredHex = grid.getHoveredHex();
  std::vector<Hex *> selectedHex = grid.getSelectedHexes();
  if (selectedHex.size() > 0) {
    _visible = false;
    return;
  }
  _visible = true;
  std::vector<Interactable *> hoverredEntities = hoverredHex.getEntities();
  // if (hoverredEntities.size() == 0) {
  //   hoverredEntities.push_back(&hoverredHex);
  // }
  for (const auto &entity : hoverredEntities) {
    _infos.push_back({entity->getName(), entity->getDescription(),
                      entity->getCustomName(), entity->getCamp(),
                      entity->getCurrAction()});
  }
}
void HoverManager::draw(sf::RenderTarget &target,
                        sf::RenderStates states) const {
  if (!_visible)
    return;
  if (_infos.size() == 0)
    return;

  sf::RectangleShape background;
  background.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
  background.setFillColor(sf::Color(224, 224, 224, 255));
  background.setOrigin(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
  background.setPosition(sf::Vector2f(target.getSize().x, target.getSize().y));
  int numOfEntities = _infos.size();
  int i = 0;
 
  sf::View currView = target.getView();
  sf::View newView = target.getDefaultView();
  target.setView(newView);
  target.draw(background);

  for (auto const &info : _infos) {
    sf::RectangleShape card;
    card.setSize(sf::Vector2f((BAR_WIDTH / numOfEntities) - (2 * MARGIN),
                              BAR_HEIGHT - 2 * PADDING));
    card.setFillColor(sf::Color(255, 255, 255, 255));
    card.setOrigin(sf::Vector2f(BAR_WIDTH / numOfEntities, BAR_HEIGHT));
    card.setPosition(
        sf::Vector2f(target.getSize().x + PADDING - (BAR_WIDTH / numOfEntities) * (numOfEntities -1 - i),
                     target.getSize().y + PADDING));
    sf::Text name;
    name.setFont(FontManager::getInstance().getFont());
    name.setString(info.name);
    name.setCharacterSize(12);
    sf::FloatRect texteBounds = name.getLocalBounds();
    name.setOrigin(texteBounds.left + texteBounds.width / 2.0f,
                    texteBounds.top + texteBounds.height / 2.0f);

    name.setFillColor(sf::Color::Black);
    name.setPosition(sf::Vector2f(card.getPosition().x,
                                  card.getPosition().y));
    target.draw(card);
    target.draw(name);
    i++;
  }

  target.setView(currView);
}
void HoverManager::setCurrentRegion(Region *reg) { _reg = reg; }
