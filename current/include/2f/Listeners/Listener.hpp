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
		Listener(); // Creates a listener
		/* Key events */
		virtual void  onKeyPressed(sf::Event *e); // When a key is pressed
		virtual void onKeyReleased(sf::Event *e); // When a key is pressed
		/* Mouse events */
		virtual void  onMouseClicked(sf::Event *e); // When there's a mouse click
		virtual void onMouseReleased(sf::Event *e); // When the mouse button is released
		virtual void    onMouseMoved(sf::Event *e); // When the mouse moves
		/* Other events */
		virtual void onInit();                    // Before first interaction
		virtual void onDisplay();                 // When displaying
		virtual void onTicked(int const& tick); // Ticked
		virtual void onClose();                   // When display time is over
		virtual void onEvent(sf::Event *e);       // Other type of event
		/* User events (easier to use) */
		virtual void  keyPressed(sf::Keyboard::Key const& key); // Key pressed
		virtual void keyReleased(sf::Keyboard::Key const& key); // Key released
		virtual void mouseClicked(sf::Mouse::Button const& b,sf::Vector2f const& pos); // Mouse clicked
		virtual void mouseReleased(sf::Mouse::Button const& b,sf::Vector2f const& pos); // Mouse released
		virtual void mouseMoved(sf::Vector2f const& pos); // Mouse moved
		// @TODO : onClose, onTick, onDisplay, onInit
	};
};

#endif