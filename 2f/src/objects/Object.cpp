#include "2f/objects/Object.hpp"

using namespace f2;

void Object::calc(int const& newticks) {
  update(newticks);
}

void Object::update(int const& newticks) {

}

sf::Vector2i Object::getCoords() {
  return sf::Vector2i(0,0);
}

void Object::relativePosition(sf::Vector2i const& center) {

}
