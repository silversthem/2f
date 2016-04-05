/*
 * The event machine handles events on listeners
 * This class is abstract because there's no frame attached to it
 */

#ifndef EVENTMACHINE_HPP
#define EVENTMACHINE_HPP

#include <vector>
/* 2f */
#include "../Listeners/Listener.hpp"
#include "../macros.hpp"

namespace F2
{
	class EventMachine
	{
	protected:
		sf::Event _event; // The event the machine will listen to
		VECTOR_OF(Listener) _listeners; // Listeners to the event machine
		/* Event handling */
		void call(Listener *l); // Handles an event for a listener
		virtual void onEvent(); // When facing an unhandled event
	public:
		EventMachine(); // Creates an event machine
		/* Adders */
		void addListener(Listener* l); // Adds a listener to the event pile
		/* Methods */
		void handle(); // Handles all events
		void close(); // Tells all elements that everything is over
	};
};

#endif