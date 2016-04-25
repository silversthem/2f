/*
 * The event machine handles events on listeners
 * This class is abstract because there's no frame attached to it
 */

#ifndef EVENTMACHINE_HPP
#define EVENTMACHINE_HPP

#include <vector>
#include <iostream>
/* 2f */
#include "../Listeners/Listener.hpp"
#include "../macros.hpp"

namespace F2
{
	class EventMachine : public Listener
	{
	protected:
		sf::Event _event; // The event the machine will listen to
		/* Event handling */
		void handle(); // Creates the callstack
	public:
		EventMachine(); // Creates an event machine
		void applyEvent(Listener *l); // Applies the callstack to an object
	};
};

#endif