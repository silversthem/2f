#include "Interval.hpp"

/* interval Structure */

inline bool interval::operator>(interval const& i)
{
	return start >= i.start;
}

inline bool interval::operator<(interval const& i)
{
	return end <= i.end;
}

inline bool interval::operator>=(interval &i)
{
	if(start >= i.start)
	{
		return i << start;
	}
	return false;
}

inline bool interval::operator<=(interval &i)
{
	if(end <= i.end)
	{
		return i << end;
	}
	return false;
}

inline bool interval::operator==(interval const& i)
{
	if(start <= i.start)
	{
		return end >= i.end;
	}
	return false;
}

inline bool interval::operator!=(interval const& i)
{
	if(start <= i.start)
	{
		return !(end >= i.end);
	}
	return true;
}

inline interval interval::operator&&(interval const& i)
{
	interval inter;
	// ...
	return inter;
}

inline Interval interval::operator||(interval const& i)
{
	Interval inter(start,end);
	// ...
	return inter;
}

inline bool interval::operator<<(float const& number)
{
	return (start <= number && number <= end);
}

/* Interval class */

Interval::Interval(float const& start, float const& end)
{
	_intervals.push_back(Interval::create(start,end));
}

/* Getters */

/* Setters */

/* Methods */

/* Static Methods */

interval Interval::create(float const& start, float const& end)
{
	interval i;
	i.start = start;
	i.end = end;
	return i;
}