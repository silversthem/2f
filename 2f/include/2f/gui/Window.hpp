/*
  A 2f window is an sfml render window containing frames
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Frame.hpp"

namespace f2 {

class Window : public sf::RenderWindow {
protected:
  Frame *currentFrame; // Current frame to display
  sf::Event currentEvent; // Current event caught by window
public:
  Window(sf::Vector2u const& size,std::string const& title); // Creating a window
  void setFrame(Frame &f); // Sets frame to be rendered
  void run(); // Running main loop for events/frame rendering
  /* Empty virtual methods */
  virtual void update(int const& nt); // Window update
};

}

#endif
