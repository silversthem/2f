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
	protected:
		bool d; // Is the object being deleted
		unsigned int _connections; // How many connections to vectors the objects has
	public:
		Listener(); // Creates a listener
		virtual ~Listener(); // Deletes a listener
		/* Deleting related */
		void deletion();   // Readies the listener to be deleted
		bool isDeleting(); // When deleted
		void connect();    // The listener has just been connected to a vector
		void disconnect(); // When deleting the object
		/* Key events */
		virtual void onKeyPressed(sf::Event::KeyEvent const& key); // When a key is pressed
		virtual void onKeyReleased(sf::Event::KeyEvent const& key); // When a key is pressed
		/* Mouse events */
		virtual void onMouseClicked(sf::Event::MouseButtonEvent const& mouse);  // When there's a mouse click
		virtual void onMouseReleased(sf::Event::MouseButtonEvent const& mouse); // When the mouse button is released
		virtual void onMouseMoved(sf::Event::MouseMoveEvent const& mouse);      // When the mouse moves
		/* Other events */
		virtual void onInit();                    // Before first interaction
		virtual void onDisplay();                 // When displaying
		virtual void onTicked(float const& tick); // Ticked
		virtual void onClose();                   // When display time is over
		virtual void onDelete();                  // When the object is being deleted
	};
};

#endif