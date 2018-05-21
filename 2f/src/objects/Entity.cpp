#include "2f/objects/Entity.hpp"

using namespace f2;

Entity::Entity() : lifetime(INFINITE_LIFETIME), orientation(0), coords(0,0), frame_pos(0,0) {

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

void Entity::relativePosition(sf::Vector2i const& c,sf::Vector2i const& bias, float const& angle) {
  frame_pos = pos(c);
  // if(angle % 360 != 0) {
  //   // int d = norme(frame_pos);
  //   // float a = std::atan2(frame_pos.y,frame_pos.x);
  //   // frame_pos.x = d*std::cos(rad(angle) + a);
  //   // frame_pos.y = d*std::sin(rad(angle) + a);
  //   // setOrientation(angle);
  // }
  frame_pos -= bias;
}

void Entity::setOrientation(float const& orn) {
  orientation = orn;
}

void Entity::orientate(float const& orn) {
  orientation = orn + orientation;
}

float Entity::getOrientation() {
  return orientation;
}

void Entity::calc(int const& newticks) {
  /* Lifetime checking */
  // lifetime = (newticks < lifetime) ? (lifetime - newticks) : 0;
  // if(lifetime == 0) setExpired(); // End of entity
  /* Updating */
  update(newticks);
}

bool Entity::inBounds(sf::IntRect const& bounds) {
  return true;
}

void Entity::render(sf::RenderTarget *t) {
  skeleton.blit(t,frame_pos);
}
