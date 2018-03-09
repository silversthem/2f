/*
 * A timer handles ticks, ticks are a predetermined duration, usually in msecs.
 * Basically at every tick the onTicked() method of objects is called, and that lets you
 * coordinates your stuff using : if(tick % x == 0){ ... }
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#define DEFAULT_MAX_TICK 100000

#include <chrono>

namespace F2
{
	class Timer
	{
	protected:
		int _tick_duration; // Tick duration in msec
		int      _max_tick; // Max ticks before max ticks gets back to 0
		int  _current_tick; // Current tick
		bool       _update; // If the tick count has updated
		/* Timers */
		std::chrono::time_point<std::chrono::system_clock> _start; // Time start
		std::chrono::time_point<std::chrono::system_clock>   _end; // End
		std::chrono::duration<double>                    _elapsed; // Delta
		/* Calculations */
		void calculate(); // Calculates the stuff
	public:
		Timer(); // Default constructor
		Timer(int const& tick_duration,int const& max_tick = DEFAULT_MAX_TICK); // Creates a timer
		/* Getters */
		int          get_tick(); // Returns current tick
		int      get_max_tick(); // Returns max tick
		int get_tick_duration(); // Returns current tick
		/* Setters */
		void set_tick_duration(int const& d); // Sets tick duration
		void    set_max_tick(int const& max); // Sets max tick 
		/* Methods */
		void   start(); // Starts the timer
		void   reset(); // Resets the timer
		/* Testers */
		bool updated(); // If the tick count has changed
		bool  is_set(); // If the timer is configured ~> if _tick_duration =/= 0
	};
};

#endif