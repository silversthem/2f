#include "../../../include/2f/Time/Ticker.hpp"

F2::Ticker::Ticker(int const& ticks)
{
	_ticks = ticks;
}

void F2::Ticker::add(Listener *l)
{
	_listeners.push_back(l);
}

void F2::Ticker::run()
{
	for(VECTOR_OF(Listener)::iterator it = _listeners.begin();it != _listeners.end();it++)
	{
		(*it)->onTicked(_ticks);
	}
}