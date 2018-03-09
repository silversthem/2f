/*
  A 2f Entity is a object with more properties :
    relative positionning (coordinates)
    lifetime (-1 = Infinite) in game ticks
*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#define INFINITE_LIFETIME -1

#include "Object.hpp"

namespace f2 {

class Entity : public Object {
protected:
  int lifetime; // Display time left (in game ticks)
  sf::Vector2i coords; // Absolute coordinates
  /* Methods */
  sf::Vector2i pos(sf::Vector2i const& relativeTo); // Calculates window's position from coordinates
public:
  Entity(); // Creates an entity
  /* Rendering methods */
  void calc(int const& newticks); // Adjusts lifetime
};

};

#endif
