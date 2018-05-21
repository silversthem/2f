#ifndef WORLD_HPP
#define WORLD_HPP

#include "Player.hpp"
#include "Zombie.hpp"

using namespace f2;

class World : public Frame {
protected:
  /* World */
  enum Entities {
    Crates,
    Bullets,
    Zombies,
    Players
  };
  /* Textures */
  sf::Texture crate_texture;
public:
  World(Player *p) : Frame() {
    /* world */
    indexer()->createSet(Crates);
    indexer()->createSet(Bullets);
    indexer()->createSet(Zombies);
    indexer()->createSet(Players);
    indexer()->get<indexers::Set>(Players)->insert(p);
    centerAround(p,true);
    background()->loadFromFile("textures/map/sand.png");
    /* events */
    handler()->subscribe(sf::Event::KeyReleased,p);
    handler()->subscribe(sf::Event::MouseMoved,p);
  }
  void create_scene() {
    /* Env */
    /* Loading textures */
    crate_texture.loadFromFile("textures/map/crate.png");
    /* Creating scene */
    Sprite *crate1 = new Sprite;
    crate1->setCoords(200,200);
    crate1->setTexture(crate_texture);
    crate1->setScale(0.3,0.3);
    crate1->centerOrigin();

    Sprite *crate2 = new Sprite;
    crate2->setCoords(-350,200);
    crate2->setTexture(crate_texture);
    crate2->setScale(0.2,0.2);
    crate2->centerOrigin();

    indexer()->get<indexers::Set>(Crates)->insert(crate1);
    indexer()->get<indexers::Set>(Crates)->insert(crate2);
    /* Mobs */

  }
  /* Events */
};

#endif
