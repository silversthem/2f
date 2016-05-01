/*
 * A listeners "listens" to call from the frame.
 * And translate event into an user function execution.
 */

#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <SFML/Window/Event.hpp>

namespace F2
{
	class Frame; // Injection

	class Listener
	{
	protected:
		virtual void handle(sf::Event *e); // Handles an event ~> Calls the user event
	public:
		Listener(); // Creates a listener
		/* System events */
		virtual void onInit();
		virtual void onClose();
		virtual void onTicked(int const& tick);
		virtual void onDisplay();
		/* User events */
		virtual void  keyPressed(sf::Keyboard::Key const& key); // Key pressed
		virtual void keyReleased(sf::Keyboard::Key const& key); // Key released
		virtual void       mouseMoved(sf::Vector2f const& pos); // Mouse moved
		virtual void  mouseClicked(sf::Mouse::Button const& b,sf::Vector2f const& pos); // Mouse clicked
		virtual void mouseReleased(sf::Mouse::Button const& b,sf::Vector2f const& pos); // Mouse released
		virtual void close(); // Called by the onClose method
		virtual void  init(); // Called by the onInit method
		virtual void otherEvent(sf::Event *e); // Called by an unhandled event
		// @TODO : onTick, onDisplay
		friend class Frame;
	};
};

#endif