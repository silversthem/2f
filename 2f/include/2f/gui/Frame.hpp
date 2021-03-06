/*
  A 2f Frame contains elements that can be rendered into a window
*/

#ifndef FRAME_HPP
#define FRAME_HPP

#include <SFML/Window/Event.hpp>
#include "../event/EventHandler.hpp"
#include "../event/KeyBoard.hpp"
#include "../containers/Indexer.hpp"
#include "../objects/Entity.hpp"
#include "Background.hpp"

namespace f2 {

class Frame : public Object {
protected:
  /* Attributes */
  KeyBoard keyboard; // KeyBoard object for key presses/releases event
  Indexer entities; // Frame elements to display
  EventHandler eventHandler; // Frame elements interacting with events
  Background bg; // Frame background
  /* Rendering properties */
  int newticks; // New ticks to count when rendering
  sf::IntRect bounds; // Frame bounds
  Entity* center; // Center all around this entity
  bool rotateCenter; // Rotates everything around centere
  sf::View view; // Frame camera
public:
  Frame(); // Creating a frame
  void centerAround(Entity *e, bool rotate = false); // Centers entities around a selected entity, (if 0 centers at coordinates)
  void setBounds(int const& w,int const& h); // Sets bounds from a pair of ints
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
  /* Pointers */
  Indexer* indexer(); // Accessing indexer
  EventHandler* handler(); // Accessing event handler
  Background* background(); // Accessing Background
};

}

#endif
