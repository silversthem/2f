#include "../../../include/2f/Time/Timer.hpp"

F2::Timer::Timer()
{
	set_max_tick(DEFAULT_MAX_TICK);
	reset();
}

F2::Timer::Timer(int const& tick_duration,int const& max_tick)
{
	set_tick_duration(tick_duration);
	set_max_tick(max_tick);
	reset();
}

/* Protected */

void F2::Timer::calculate()
{
	_end = std::chrono::system_clock::now();
	_elapsed = _end - _start;
	int e = (int) (_elapsed.count() * 1000);
	if(e >= _tick_duration && e > 0)
	{
		_update = true;
		int t = (e - (e % _tick_duration))/_tick_duration;
		_current_tick += t;
		if(_current_tick >= _max_tick)
		{
			_current_tick = 0;
		}
		_start = _end;
	}
	else
	{
		_update = false;
	}
}

/* Getters */

int F2::Timer::get_tick() // Returns current tick
{
	calculate();
	return _current_tick;
}

int F2::Timer::get_max_tick()
{
	return _max_tick;
}

int F2::Timer::get_tick_duration()
{
	return _tick_duration;
}

/* Setters */

void F2::Timer::set_tick_duration(int const& d)
{
	_tick_duration = d;
}

void F2::Timer::set_max_tick(int const& max)
{
	_max_tick = max;
}

/* Methods */

void F2::Timer::start()
{
	reset();
}

void F2::Timer::reset()
{
	_update = true;
	_current_tick = 0;
	_start = std::chrono::system_clock::now();
}

bool F2::Timer::is_set()
{
	return _tick_duration != 0;
}

bool F2::Timer::updated()
{
	return _update;
}