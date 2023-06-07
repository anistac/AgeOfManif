#include "Menu.hpp"
#include "FontManager.hpp"
#include "Win.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>

void Menu::handleEvent(sf::Event event) {
  int buttonPressed;
  // Si l'utilisateur clique sur le bouton gauche de la souris
  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == sf::Mouse::Left) {
    // Mettre à jour la position de la souris
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*_win);

    for (int i = 0; i < buttons.size(); ++i) {
      const auto &button = buttons[i];
      if (sf::Mouse::getPosition(*_win).x >= button.getPosition().x &&
          sf::Mouse::getPosition(*_win).x <=
              button.getPosition().x + button.getSize().x &&
          sf::Mouse::getPosition(*_win).y >= button.getPosition().y &&
          sf::Mouse::getPosition(*_win).y <=
              button.getPosition().y + button.getSize().y) {
        buttonPressed = i;
        Menu::selectedWin = i; // Repasse sur le showMain
        std::cout << i << std::endl;
      }
    }
  }
}

Menu::Menu(sf::RenderWindow &win) {
  _win = &win;
  // Charger l'image de fond à partir d'un fichier
  backgroundImage.loadFromFile("../assets/carteDeFrance.png");
  if (!backgroundImage.loadFromFile("../assets/carteDeFrance.png")) {
    throw std::runtime_error("impossible de charger la carte mskn");
  }
  _sprite.setTexture(backgroundImage);

  _imagerobot.loadFromFile("../assets/robot.png");
  if (!_imagerobot.loadFromFile("../assets/robot.png")) {
    throw std::runtime_error("impossible de charger le robot mskn");
  }
  _spriterobot.setTexture(_imagerobot);
  _spriterobot.setScale(0.7f, 0.7f); // Réduit la taille du sprite à 50%
  _spriterobot.setPosition(650, 0);

  _text.setFont(FontManager::getInstance().getFont());
  _text.setString("   Bonjour,\nOu voulez-vous\n   allez?");
  _text.setPosition(685, 15);
  _text.setCharacterSize(12);
  _text.setFillColor(sf::Color::Black);

  // Ajouter des éléments à la structure regions : Affichage des nom des régions
  // sur la carte
  regions.push_back({"Ile De France", {400, 210}});
  regions.push_back({"Vendee", {220, 320}});
  regions.push_back({"Normandie", {260, 200}});
  regions.push_back({"Bretagne", {100, 270}});
  regions.push_back({"Grand Est", {600, 210}});
  regions.push_back({"Grand Nord", {430, 90}});
  regions.push_back({"Bourgogne", {550, 350}});
  regions.push_back({"Val-de-Loire", {350, 330}});
  regions.push_back({"Aquitaine", {300, 500}});
  regions.push_back({"Rhone-Alpes", {500, 520}});
  regions.push_back({"Region Paca", {630, 650}});
  regions.push_back({"Occitanie", {400, 650}});

  std::vector<sf::Text> regionTexts;
  for (auto it = regions.begin(); it != regions.end(); ++it) {
    sf::Text texte;
    texte.setFont(FontManager::getInstance().getFont());
    texte.setString(it->region);
    texte.setCharacterSize(20);
    texte.setFillColor(sf::Color::White);
    texte.setPosition(it->position.first, it->position.second);
    regionTexts.push_back(texte);
  }

  // Créer les texte s : titre des régions
  std::vector<std::string> regionNames = {
      "Ile De France", "Vendee",      "Normandie",   "Bretagne",
      "Grand Est",     "Grand Nord",  "Bourgogne",   "Val-de-Loire",
      "Aquitaine",     "Rhone-Alpes", "Region Paca", "Occitanie"};

  float buttonX = 30.0f;
  float buttonY = 30.0f;
  float buttonSpacing = 40.0f;
  int iterator = 1;

  for (const auto &regionName : regionNames) {
    sf::RectangleShape button(sf::Vector2f(150, 30));
    button.setFillColor(sf::Color::Black);
    button.setPosition(buttonX, buttonY);

    sf::Text buttonText;
    buttonText.setFont(FontManager::getInstance().getFont());
    buttonText.setString(regionName);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(buttonX, buttonY);
    mousePositions.push_back(std::make_pair(buttonX, buttonY));

    buttons.push_back(button);
    buttonTexts.push_back(buttonText);

    iterator += 1;
    if (iterator == 5)
      buttonY += 220;
    buttonY += buttonSpacing;
  }
}

void Menu::makeTick() {
  sf::View currView = _win->getView();
  _win->setView(_win->getDefaultView());
  _win->draw(_sprite);
  _win->draw(_spriterobot);
  _win->draw(_text);
  for (const auto &button : buttons) {
    _win->draw(button);
  }

  for (const auto &buttonText : buttonTexts) {
    _win->draw(buttonText);
  }

  for (auto it = regions.begin(); it != regions.end(); ++it) {
    sf::Text temp;
    temp.setFont(FontManager::getInstance().getFont());
    temp.setString(it->region);
    temp.setCharacterSize(20);
    temp.setFillColor(sf::Color::Black);
    temp.setPosition(it->position.first, it->position.second);
    _win->draw(temp);
  }
}
