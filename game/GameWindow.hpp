#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "World.hpp"
#include <SFML/Window/Mouse.hpp>

using namespace f2;

class GameWindow : public Window {
protected:
  Player *player;
  World *world;
public:
  GameWindow() : GameWindow::Window(sf::Vector2u(800,800), "Game") {
    player = new Player;
    world  = new World(player);
    setFrame(*world);
    world->setBounds(getSize().x,getSize().y);
    world->create_scene();
    setFramerateLimit(120); // @TODO : ;)
    setMouseCursorVisible(false);
  }
  void update(int const& nt) {
    sf::Mouse::setPosition(sf::Vector2i(getSize().x/2,getSize().y/2), *this);
  }
};

#endif
