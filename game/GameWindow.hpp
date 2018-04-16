#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "World.hpp"

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
    world->setBounds(800,800);
    setFramerateLimit(60); // @TODO : ;)
  }
};

#endif
