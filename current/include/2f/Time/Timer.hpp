/*
 * A timer is a collection of tickers in charge of counting a checking the ticks
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <map>
/* 2f */
#include "Ticker.hpp"

namespace F2
{
	class Timer
	{
	protected:
		int _delay; // A tick in msec
		int _loop;  // How many ticks before we go to 0 again
		int _currentCount; // Current ticks
		std::map<int,Ticker*> _tickers; // Tickers, with the ticks to tick
		/* Methods */
		void calculate(); // Calculates current tick
	public:
		Timer();                             // Creates an empty timer
		Timer(int const& d,int const& loop); // Creates a timer
		~Timer(); // Deletes the tickers
		/* Setters */
		void setTickDelay(int const& d); // Sets tick delay for the timer
		void setTicksLoop(int const& l); // Sets how many ticks it takes before getting back to 0
		/* Adders  */
		void addTicker(int const& ticksRequired); // Adds a ticker for a certain amount of time
		void addToTicker(int const& tick,Listener* l); // Adds a listener to a ticker
		/* Accessors */
		Ticker* ticker(int const& index); // Access a certain ticker
		/* Methods */
		void tick(); // Runs the timer, and ticks it
	};
};

#endif