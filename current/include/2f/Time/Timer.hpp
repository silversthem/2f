/*
 * A timer handles ticks, ticks are a predetermined duration, usually in msecs.
 * Basically at every tick the onTicked() method of objects is called, and that lets you
 * coordinates your stuff using : if(tick % x == 0){ ... }
 */

#ifndef TIMER_HPP
#define TIMER_HPP

namespace F2
{
	class Timer
	{
	public:
		Timer();
	};
};

#endif