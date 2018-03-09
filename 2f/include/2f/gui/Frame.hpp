/*
  A 2f Frame contains elements that can be rendered into a window
*/

#ifndef FRAME_HPP
#define FRAME_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "../event/Listener.hpp"
#include "../containers/Indexer.hpp"
#include "../objects/Entity.hpp"

namespace f2 {

class Frame : public Object {
protected:
  /* Attributes */
  Indexer entities; // Frame elements to display
  Listener listeners; // Frame elements interacting with events
  /* Rendering properties */
  int newticks; // New ticks to count when rendering
  sf::IntRect bounds; // Frame bounds
public:
  Frame(); // Creating a frame
  void centerAround(Entity const& e); // Centers entities around a selected entity, (if 0 centers at coordinates)
  /* Event as main frame */
  void handle(sf::Event const& e); // Handling event through listener
  /* Event as object */
  // ...
  /* Rendering as an object */
  bool inBounds(sf::IntRect const& bonds); // Object inherited method
  void calc(int const& nt); // Sets newticks when rendering
  void render(sf::RenderTarget *t); // Rendering/Updating frame
  /* Rendering as main frame */
  void render(sf::RenderTarget *t,int const& nt); // Renders frame
  Indexer* indexer(); // Accessing indexer
};

}

#endif
