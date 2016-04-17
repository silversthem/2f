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
		std::vector<std::pair<void (Listener::*)(const sf::Event&),sf::Event> > _callstack; // List of listeners to call
		/* Event handling */
		void init();                  // Boots the event machine
		virtual void onEvent();       // When facing an unhandled event
		void applyEvent(Listener *l); // Applies the callstack to an object
		void handle();                // Creates the callstack
	public:
		EventMachine(); // Creates an event machine
		std::pair<void (Listener::*)(const sf::Event&),sf::Event> createPair(void (Listener::*action)(const sf::Event&),sf::Event const& e);
	};
};

#endif