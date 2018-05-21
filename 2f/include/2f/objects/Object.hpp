/*
  A 2f object is the base class for all rendered elements, it handles time updates and events
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "../event/Listener.hpp"
#include "../containers/Indexer.hpp"

namespace f2 {

class Object : public IndexedElement {
public:
  /* Event methods */
  // ...
  /* Rendering methods */
  virtual void calc(int const& newticks); // Called just before rendering
  virtual void update(int const& newticks); // Empty function for user to overload
  virtual void relativePosition(sf::Vector2i const& coords,sf::Vector2i const& bias, float const& angle = 0); // Centers object position around coordinates
  virtual sf::Vector2i getCoords();
  /* Abstract rendering methods */
  virtual bool inBounds(sf::IntRect const& bounds) = 0; // if the object position is inside a rectangle
  virtual void render(sf::RenderTarget *t) = 0; // Renders object
};

}

#endif
