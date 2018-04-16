#include "2f/event/EventHandler.hpp"

using namespace f2;

EventHandler::EventHandler() {

}

void EventHandler::clickable(int const& mclick, Listener *l) {

}

void EventHandler::subscribe(int const& event, Listener* l) {
  if(listeners.find(event) != listeners.end()) {
    listeners[event].insert(l);
  } else {
    Listeners s;
    s.insert(l);
    listeners[event] = s;
  }
}

void EventHandler::handle(sf::Event const& event) {
  if(listeners.find(event.type) != listeners.end()) {
    Listeners::iterator i = listeners[event.type].begin();
    /* finding method to call */
    for(;i != listeners[event.type].end();i++) {
      switch (event.type) {
        case sf::Event::KeyPressed:
          (*i)->onKeyPressed(event.key.code);
        break;
        case sf::Event::KeyReleased:
          (*i)->onKeyReleased(event.key.code);
        break;
        case sf::Event::MouseMoved:
          (*i)->onMouseMoved(event.mouseMove.x,event.mouseMove.y);
        break;
      }
    }
  }
}
