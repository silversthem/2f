/*

*/

#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "Listener.hpp"
#include "MouseHandler.hpp"

#include <SFML/Window/Event.hpp>
#include <map>

namespace f2 {

class EventHandler {
protected:
  EventListeners listeners;
  MouseHandler onclicked;
public:
  EventHandler();
  void clickable(int const& mclick, Listener *l);
  void subscribe(int const& event, Listener* l);
  void handle(sf::Event const& event);
};

}

#endif
