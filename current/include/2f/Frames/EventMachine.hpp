/*
 * The event machine handles events on listeners
 * This class is abstract because there's no frame attached to it
 */

#ifndef EVENTMACHINE_HPP
#define EVENTMACHINE_HPP

#include "../Listeners/Listener.hpp"
#include "../macros.hpp"

namespace F2
{
	class EventMachine
	{
	protected:
		sf::Event _events; // The event the machine will listen to
		VECTOR_OF(Listener) _listeners; // Listeners to the event machine
		/* Event handling */
	public:
		/* Adders */
	};
};

#endif