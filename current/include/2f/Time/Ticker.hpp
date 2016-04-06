/*
 * A ticker calls the onTicked method of listeners when a certain amount of ticks has passed
 * This is used to time movements and other things (sprite texture change in a walking animation for example)
 */

#ifndef TICKER_HPP
#define TICKER_HPP

#include <vector>
/* 2f */
#include "../Listeners/Listener.hpp"
#include "../macros.hpp"

namespace F2
{
	class Ticker
	{
	protected:
		int _ticks;                     // Tick value associated with listener
		VECTOR_OF(Listener) _listeners; // Listeners associated to the ticker
	public:
		Ticker(int const& ticks); // Creates a ticker
		/* Adders */
		void add(Listener *l); // Adds a listener to the ticking pile
		/* Methods */
		void run(); // Calls the onTicked method on all listeners
	};
};

#endif