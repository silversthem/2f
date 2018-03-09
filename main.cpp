#include <2f.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace f2;

class Game : public Window {
protected:
  Player p;
public:
  Game() {
    p.setCoords(sf::Vector2i(0,0));
    currentFrame = new Frame();
    currentFrame->indexer()->insert(&p);
    currentFrame->centerAround(&p);
  }
  ~Game() {
    delete currentFrame;
  }
};

class Player : public Sprite {
  static const walk_speed = 5;
  static const run_speed  = 15;
protected:
    int speed;
    sf::Vector2i motion;
public:
  Player() {
    speed  = 0;
    motion = sf::Vector2i(0,0);
  }
  void update(int const& nt) {

  }
};

int main() {
  /* Creating window */
  Window w(sf::Vector2u(800,600),"Test Window");
  w.setFramerateLimit(30); // @TODO : Use timer instead
  /* Creating Frame */
  Frame f;



  /* Running window */
  w.setFrame(f);
  w.run();
  return 0;
}
