/*
  A 2f object is the base class for all rendered elements, it handles time updates and events
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "../containers/Indexer.hpp"

namespace f2 {

class Object : public Indexed_Element {
public:
  /* Event methods */
  // ...
  /* Rendering methods */
  void calc(int const& newticks); // Called just before rendering
  virtual void update(int const& newticks); // Empty function for user to overload
  void centerAround(sf::Vector2i const& center); // Centers object position around coordinates
  /* Abstract rendering methods */
  virtual bool inBounds(sf::IntRect const& bonds) = 0; // if the object position is inside a rectangle
  virtual void render(sf::RenderTarget *t) = 0; // Renders object
};

}

#endif
