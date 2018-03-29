#include "2f/objects/Entity.hpp"

using namespace f2;

Entity::Entity() : lifetime(INFINITE_LIFETIME) {

}

sf::Vector2i Entity::pos(sf::Vector2i const& relativeTo) {
  return sf::Vector2i(coords.x - relativeTo.x,coords.y - relativeTo.y);
}

void Entity::setCoords(int const& x,int const& y) {
  coords.x = x;
  coords.y = y;
}

void Entity::move(int const& x, int const& y) {
  coords.x += x;
  coords.y += y;
}

sf::Vector2i Entity::getCoords() {
  return coords;
}

void Entity::relativePosition(sf::Vector2i const& center) {

}

void Entity::calc(int const& newticks) {
  /* Lifetime checking */
  lifetime = (newticks < lifetime) ? (lifetime - newticks) : 0;
  if(lifetime == 0) setExpired(); // End of entity
  /* Updating */
  update(newticks);
}
