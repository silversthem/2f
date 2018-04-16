#ifndef WORLD_HPP
#define WORLD_HPP

#include "Player.hpp"

using namespace f2;

class World : public Frame {
public:
  World(Player *p) : Frame() {
    // indexer()->create_hash("crates");
    indexer()->insert("player",p,Indexer::Single);
    centerAround(p,false);
    background()->loadFromFile("textures/map/sand.png");
    /* events */
    handler()->subscribe(sf::Event::KeyPressed,p);
    handler()->subscribe(sf::Event::KeyReleased,p);
    // handler()->subscribe(sf::Event::MouseMoved,p);
  }
};

#endif
