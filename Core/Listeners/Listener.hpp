#ifndef LISTENER_HPP_INCLUDED
#define LISTENER_HPP_INCLUDED

/* A listener is called when event are produced */

#include <SFML/Window/Event.hpp>

class Listener
{
public: // events
	virtual void onInit(); // when added in the frame
	virtual void ticked(float tick); // Called by a ticker when it's time to be updated
	virtual void onMouseClicked(sf::Event::MouseButtonEvent const& mouse); // on click
	virtual void onMouseReleased(sf::Event::MouseButtonEvent const& mouse); // on release
	virtual void onMouseMoved(sf::Event::MouseMoveEvent const& mouse); // on movement
	virtual void onKeyPressed(sf::Event::KeyEvent const &key); // on key pressed
	virtual void onKeyReleased(sf::Event::KeyEvent const &key); // on key released
};

#endif