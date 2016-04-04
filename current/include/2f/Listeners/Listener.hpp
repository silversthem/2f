/*
 * A listeners "listens" to call from the event machine
 * Whenever an event happens, the event machine calls a method from the listener
 */

#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <SFML/Window/Event.hpp>

namespace F2
{
	class Listener
	{
	public:
		/* Key events */
		virtual void onKeyPressed(sf::Event::KeyEvent const& key); // When a key is pressed
		virtual void onKeyReleased(sf::Event::KeyEvent const& key); // When a key is pressed
		/* Mouse events */
		virtual void onMouseClicked(sf::Event::MouseButtonEvent const& mouse); // When there's a mouse click
		virtual void onMouseReleased(sf::Event::MouseButtonEvent const& mouse); // When the mouse button is released
		virtual void onMouseMoved(sf::Event::MouseMoveEvent const& mouse); // When the mouse moves
		/* Other events */
		virtual void onInit(); // Before first interaction
		virtual void onDisplay(); // When displaying
		virtual void onClose(); // When display time is over
	};
};

#endif