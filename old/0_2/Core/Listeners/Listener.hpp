#ifndef LISTENER_HPP_INCLUDED
#define LISTENER_HPP_INCLUDED

/* A listener is called when event are produced */

#include <SFML/Window/Event.hpp>

class Listener
{
protected:
	/* Overridable events */
	virtual void keyPressed(sf::Event::KeyEvent const &key); // Called in the beginning of onKeyPressed
	virtual void keyReleased(sf::Event::KeyEvent const &key); // Called in the beginning of onKeyReleased
public: // events
	/* In frame event */
	virtual void onInit(); // when added in the frame
	virtual void ticked(float tick); // Called by a ticker when it's time to be updated
	virtual void onDelete(); // When deleting the listener
	/* Mouse events */
	virtual void onMouseClicked(sf::Event::MouseButtonEvent const& mouse); // on click
	virtual void onMouseReleased(sf::Event::MouseButtonEvent const& mouse); // on release
	virtual void onMouseMoved(sf::Event::MouseMoveEvent const& mouse); // on movement
	/* Key events */
	virtual void onKeyPressed(sf::Event::KeyEvent const &key); // on key pressed
	virtual void onKeyReleased(sf::Event::KeyEvent const &key); // on key released
};

#endif