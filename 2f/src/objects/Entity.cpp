#include "2f/objects/Entity.hpp"

using namespace f2;

Entity::Entity() : lifetime(INFINITE_LIFETIME) {

}

void Entity::calc(int const& newticks) {
  /* Lifetime checking */
  lifetime = (newticks < lifetime) ? (lifetime - newticks) : 0;
  if(lifetime == 0) setExpired(); // End of entity
  /* Updating */
  update(newticks);
}
