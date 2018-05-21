/*
  A 2f Entity is a object with more properties :
    relative positionning (coordinates)
    lifetime (-1 = Infinite) in game ticks
*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#define INFINITE_LIFETIME -1

#include <cmath> // cos & sin
#include "Object.hpp"
#include "../graphics/Skeleton.hpp"

#define rad(x) x*(3.14/180)
#define deg(x) x*(180/3.14)
#define norme(a) std::sqrt(a.x*a.x + a.y*a.y)

namespace f2 {

class Entity : public Object {
protected:
  int lifetime; // Display time left (in game ticks)
  sf::Vector2i coords; // Absolute coordinates
  sf::Vector2i frame_pos; // position in current frame
  float orientation; // Current orientation, in degs
  Skeleton skeleton; // Entity texture skeleton
  /* Methods */
  sf::Vector2i pos(sf::Vector2i const& relativeTo); // Calculates frame's position from coordinates
public:
  Entity(); // Creates an entity
  /* setters */
  void setCoords(int const& x,int const& y); // sets entity coords
  void move(int const& x, int const& y); // Moves coords
  void setOrientation(float const& orn);
  void orientate(float const& orn);
  /* getters */
  sf::Vector2i getCoords();
  float getOrientation();
  /* Rendering methods */
  virtual void relativePosition(sf::Vector2i const& coords,sf::Vector2i const& bias, float const& angle = 0); // Adjusts position relative to another entity's coords
  virtual void calc(int const& newticks); // Adjusts lifetime
  bool inBounds(sf::IntRect const& bounds); // Returns true if entity is in frame
  void render(sf::RenderTarget *t); // Renders entity
};

};

#endif
