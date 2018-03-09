#include "2f/gui/Window.hpp"

using namespace f2;

Window::Window(sf::Vector2u const& size,std::string const& title) {
  create(sf::VideoMode(size.x,size.y),title);
	setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width - size.x)/2,(sf::VideoMode::getDesktopMode().height - size.y)/2));
  currentFrame = 0;
}

void Window::setFrame(Frame &f) {
  currentFrame = &f;
}

void Window::run() {
  if(currentFrame == 0) close(); // No frame -> Nothing to do
  while(isOpen()) {
    /* Checking Frame */
    /* Time handling */
    // ...
    /* Event handling */
    while(pollEvent(currentEvent)) {
      if(currentEvent.type == sf::Event::Closed) { // Window closing
        close();
      } else { // Other event -> Frame
        currentFrame->handle(currentEvent);
      }
    }
    /* Rendering */
    clear(sf::Color::Black);
    currentFrame->calc(1); // Updating frame
    currentFrame->render(this); // Rendering Frame
    display();
  }
}
