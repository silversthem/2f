#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <2f.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace f2;

class Player : public Entity, public Listener {
  /* Entity states */
  enum State {IDLE, WALK, RUN};
  enum Equipment {FLASHLIGHT, KNIFE, WEAPON};
  /* Class constants */
  static const int walk_speed = 5;
  static const int run_speed  = 15;
protected:
  /* Attributes */
  int movement_dir[2];
  State state;
  Sprite *feet;
  sf::Texture move_knife_texture;
  sf::Texture idle_knife_texture;
  sf::Texture move_feet_texture;
  Animations::LinearAnimation move_knife;
  Animations::LinearAnimation idle_knife;
  Animations::LinearAnimation move_feet;
  /* stored values */
  sf::Vector2i lastMousePos;
public:
  Player() :
    move_knife(&move_knife_texture,320,320,4,5,1),
    idle_knife(&idle_knife_texture,320,320,4,5,3),
    move_feet(&move_feet_texture,210,210,4,5,1)
  {
    lifetime = INFINITE_LIFETIME;
    setCoords(0,0);
    move_knife_texture.loadFromFile("textures/player/knife/move.png");
    idle_knife_texture.loadFromFile("textures/player/knife/idle.png");
    move_feet_texture.loadFromFile("textures/player/feet/walk.png");
    state = IDLE;
    movement_dir[0] = 0;movement_dir[1] = 0;
    skeleton.add("player",sf::Vector2i(0,0),&idle_knife);
    skeleton.add("feet",sf::Vector2i(15,-10),&move_feet);
    skeleton.setScale(0.3,0.3);
    skeleton.foreach([](SkeletonPart& sp) {
      sp.second->setRotation(-90);
    });
  }
  void update(int const& nt) {
    if(state == RUN) {
      Entity::move(8*movement_dir[0],8*movement_dir[1]);
    } else if(state == IDLE) {

    }
  }
  /* Events */
  void onKeyPressed(int const& kcode) {
    if(kcode == sf::Keyboard::Key::Z) {
      state = RUN;
      movement_dir[1] = -1;
    } else if(kcode == sf::Keyboard::Key::S) {
      state = RUN;
      movement_dir[1] = 1;
    }
    if(kcode == sf::Keyboard::Key::Q) {
      state = RUN;
      movement_dir[0] = -1;
    } else if(kcode == sf::Keyboard::Key::D) {
      state = RUN;
      movement_dir[0] = 1;
    }
  }
  void onKeyReleased(int const& kcode) {
    if(kcode == sf::Keyboard::Key::Z || kcode == sf::Keyboard::Key::S) {
      movement_dir[1] = 0;
    }
    if(kcode == sf::Keyboard::Key::Q || kcode == sf::Keyboard::Key::D) {
      movement_dir[0] = 0;
    }
    if(movement_dir[0] == 0 && movement_dir[1] == 0) state = IDLE;
  }
  void onMouseMoved(int const& x, int const& y) {
    // int x2 = x - getPosition().x;
    // int y2 = y - getPosition().y;
    // lastMousePos.x = x;
    // lastMousePos.y = y;
  }
};

#endif
