#include <iostream>
#include <2f.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace f2;

class Player : public Sprite {
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
  LinearAnimation move_knife;
  LinearAnimation idle_knife;
  LinearAnimation move_feet;
public:
  Player() :
    move_knife(&move_knife_texture,320,320,4,5,1),
    idle_knife(&idle_knife_texture,320,320,4,5,1),
    move_feet(&move_feet_texture,210,210,4,5,1)
  {
    setCoords(0,0);
    move_knife_texture.loadFromFile("textures/player/knife/move.png");
    idle_knife_texture.loadFromFile("textures/player/knife/idle.png");
    move_feet_texture.loadFromFile("textures/player/feet/walk.png");
    feet = new Sprite();
    state = IDLE;
    movement_dir[0] = 0;movement_dir[1] = 0;
  }
  void onConnected() {
    root->insert("feet",feet);
  }
  void change_feet_text(int const& dir) {
    std::pair<sf::Texture*,sf::IntRect> fp = move_feet.update(dir);
    feet->setTexture(*fp.first);
    feet->setTextureRect(fp.second);
  }
  void change_player_text(int const& nt) {
    std::pair<sf::Texture*,sf::IntRect> p;
    switch (state) {
      case IDLE:
        p = idle_knife.update(nt);
      break;
      case RUN:
        p = move_knife.update(nt);
      break;
      case WALK:
        p = move_knife.update(nt);
      break;
    }
    setTexture(*p.first);
    setTextureRect(p.second);
  }
  void update(int const& nt) {
    change_player_text(nt);
    centerOrigin();
    setScale(0.7,0.7);
    setRotation(-90);
    if(state == RUN) {
      change_feet_text(nt);
      if(movement_dir[1] > 0) {
        Entity::move(0,10);
      } else if(movement_dir[1] < 0) {
        Entity::move(0,-10);
      }
    } else if(state == IDLE) {
      change_feet_text(0);
    }
    feet->setCoords(getCoords().x - 80, getCoords().y + 80);
    feet->setScale(0.7,0.7);
    feet->setRotation(-90);
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
  }
  void onKeyReleased(int const& kcode) {
    if(kcode == sf::Keyboard::Key::Z || kcode == sf::Keyboard::Key::S) {
      state = IDLE;
      movement_dir[1] = 0;
    }
  }
  void onMouseMoved(int const& x, int const& y) {

  }
};

int main() {
  /* Creating window */
  Window w(sf::Vector2u(600,600),"Test Window");
  w.setFramerateLimit(30); // @TODO : Use timer instead
  /* Creating Frame */
  Frame f;
  f.setBounds(600,600);

  Player p;

  p.centerOrigin();
  f.centerAround(&p);
  f.indexer()->insert("player",&p);
  f.handler()->subscribe(sf::Event::KeyPressed,&p);
  f.handler()->subscribe(sf::Event::KeyReleased,&p);

  /* Running window */
  w.setFrame(f);
  w.run();
  return 0;
}
