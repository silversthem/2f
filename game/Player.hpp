#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <2f.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace f2;

class PlayerTexture : public Animations::LinearAnimation {
protected:
  sf::Texture idle_knife;
  sf::Texture move_knife;
public:
  PlayerTexture() : Animations::LinearAnimation(&idle_knife,320,320,4,5,2) {
    centerOrigin();
    idle_knife.loadFromFile("textures/player/handgun/idle.png");
    move_knife.loadFromFile("textures/player/handgun/move.png");
  }
  void update(int const& nt, TextureStates const& sts) {
    if(sts.size > 0) {
      switch (sts.states[0]) {
        case 0:
          setInterval(10);
          setTexture(idle_knife);
        break;
        case 4:
          setInterval(2);
          setTexture(move_knife);
        break;
      }
    }
    Animations::LinearAnimation::update(nt,sts);
  }
};

class FeetTexture : public Animations::LinearAnimation {
protected:
  sf::Texture feet_texture;
public:
  FeetTexture() : Animations::LinearAnimation(&feet_texture,210,210,4,5,2) {
    centerOrigin();
    feet_texture.loadFromFile("textures/player/feet/walk.png");
  }
  void update(int const& nt, TextureStates const& sts) {
    if(sts.size > 0) {
      switch (sts.states[0]) {
        case 0:
          Animations::LinearAnimation::update(0,sts);
        break;
        case 4:
          Animations::LinearAnimation::update(nt,sts);
        break;
      }
    }
  }
};

class Player : public Entity, public Listener {
  /* Entity states */
  enum State {IDLE, WALK, STRAFE_LEFT, STRAFE_RIGHT, RUN};
  enum Equipment {FLASHLIGHT, KNIFE, WEAPON};
  /* Class constants */
  static const int walk_speed = 5;
  static const int run_speed  = 15;
protected:
  /* Attributes */
  sf::Vector2f movement_dir;
  float currentRotate;
  State state;
  /* Textures */
  PlayerTexture playerTexture;
  FeetTexture feetTexture;
  /* stored values */
  sf::Vector2i lastMousePos;
public:
  /* Constructor */
  Player() : currentRotate(0),state(IDLE),movement_dir(0,0)
  {
    setCoords(0,0);
    setOrientation(0);
    skeleton.add("player",sf::Vector2i(0,0),&playerTexture);
    skeleton.add("feet",sf::Vector2i(0,0),&feetTexture);
    skeleton.setScale(0.3,0.3);
    skeleton.setRotation(-90);
  }
  /* Interaction */
  void computeMotion() {
    movement_dir.x = 0;
    movement_dir.y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
      state = RUN;
      movement_dir.y -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
      state = RUN;
      movement_dir.y += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
      state = RUN;
      movement_dir.x -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      state = RUN;
      movement_dir.x += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
      orientate(-5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
      orientate(5);
    }
    if(movement_dir.x == 0 && movement_dir.y == 0) state = IDLE;
  }
  /* Methods */
  void update(int const& nt) {
    int textStates[1] = {state};
    computeMotion();
    if(state == RUN) {
      sf::Vector2f a;
      int speed = 4;
      a.x = speed*movement_dir.x*std::cos(rad(getOrientation())) - speed*movement_dir.y*std::sin(rad(getOrientation()));
      a.y = speed*movement_dir.x*std::sin(rad(getOrientation())) + speed*movement_dir.y*std::cos(rad(getOrientation()));
      Entity::move(a.x,a.y);
    }
    skeleton.setRotation(getOrientation() - 90);
    skeleton.update(nt,TextureStates(state,textStates));
  }
  /* Events */
  void onMouseMoved(int const& x, int const& y) {
    int x2 = x - getPosition().x;
    if(x2 > lastMousePos.x) orientate(0.5);
    else if(x2 < lastMousePos.x) orientate(-0.5);
    lastMousePos.x = x2;
  }
};

#endif
