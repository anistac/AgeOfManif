#include "HoverManager.hpp"
#include "FontManager.hpp"
#include "Grid.hpp"
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
        sf::Vector2f(target.getSize().x + PADDING -
                         (BAR_WIDTH / numOfEntities) * (numOfEntities - 1 - i),
                     target.getSize().y + PADDING));
    sf::Text name;
    sf::Text description;
    sf::Text busy;
    description.setFont(FontManager::getInstance().getFont());
    description.setCharacterSize(12);
    description.setString(info.description);
    description.setFillColor(sf::Color::Black);

    name.setFont(FontManager::getInstance().getFont());
    name.setCharacterSize(12);
    name.setString(info.name);
    name.setOrigin(
        name.getLocalBounds().left + name.getLocalBounds().width / 2.0f,
        name.getLocalBounds().top + name.getLocalBounds().height / 2.0f);
    name.setFillColor(sf::Color::Black);
    name.setPosition(
        sf::Vector2f(card.getPosition().x - (BAR_WIDTH / numOfEntities) / 2.0f,
                     card.getPosition().y - BAR_HEIGHT + 2 * PADDING));
    description.setPosition(card.getPosition().x -
                                (BAR_WIDTH / numOfEntities) / 2.0f,
                            card.getPosition().y - BAR_HEIGHT + 2 * PADDING +
                                name.getLocalBounds().height);
    description.setOrigin(description.getLocalBounds().left +
                              description.getLocalBounds().width / 2.0f,
                          description.getLocalBounds().top +
                              description.getLocalBounds().height / 2.0f);

    busy.setFont(FontManager::getInstance().getFont());
    busy.setCharacterSize(12);
    if (info.currAction != nullptr) {
      busy.setString("Busy doing " + info.currAction->getName());
      busy.setFillColor(sf::Color::Red);
    } else {
      busy.setString("Free");
      busy.setFillColor(sf::Color::Green);
    }
    busy.setOrigin(
        busy.getLocalBounds().left + busy.getLocalBounds().width / 2.0f,
        busy.getLocalBounds().top + busy.getLocalBounds().height / 2.0f);
    busy.setPosition(card.getPosition().x - (BAR_WIDTH / numOfEntities) / 2.0f,
                     card.getPosition().y - BAR_HEIGHT + 5 * PADDING +
                         name.getLocalBounds().height +
                         description.getLocalBounds().height);
    target.draw(card);
    target.draw(name);
    target.draw(description);
    target.draw(busy);
    i++;
  }

  target.setView(currView);
}
void HoverManager::setCurrentRegion(Region *reg) { _reg = reg; }
