#include "interval.hpp"

using namespace Math;

Interval::Interval(F2::Interval interval)
{
	_interval = interval;
}

/* Getters */

F2::Interval Interval::getInterval()
{
	return _interval;
}

F2::Interval_Member Interval::getStart()
{
	return _interval.Start;
}

F2::Interval_Member Interval::getEnd()
{
	return _interval.End;
}

std::vector<F2::Interval> Interval::getUnions()
{
	return _unions;
}

F2::Interval Interval::getUnion(unsigned int id)
{
	if(id < _unions.size())
	{
		return _unions[id];
	}
	F2::Interval i;
	i.Start.Value = 0;
	i.End.Value = -1;
	return i;
}

/* Setters */

void Interval::setStart(F2::Interval_Member member)
{
	_interval.Start = member;
}

void Interval::setEnd(F2::Interval_Member member)
{
	_interval.End = member;
}

void Interval::setInterval(F2::Interval interval)
{
	_interval = interval;
}

/* Pointers */

F2::Interval* Interval::interval()
{
	return &_interval;
}

std::vector<F2::Interval>* Interval::unions()
{
	return &_unions;
}

/* Methods */



/* Static methods */