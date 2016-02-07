#include "interval.hpp"

Interval::Interval(float start,float end)
{
	setInterval(start,end);
}

Interval Interval::interval(float start,float end)
{
	Interval i(start,end);
	return i;
}

/* getters */

float Interval::getStart()
{
	return _start;
}

float Interval::getEnd()
{
	return _end;
}

std::vector<Interval> Interval::getUnions()
{
	return _unions;
}

/* setters */

void Interval::setInterval(float start,float end)
{
	_start = start;
	_end = start;
}

void Interval::setUnions(std::vector<Interval> &unions)
{
	_unions = unions;
}

/* adders */

void Interval::addUnion(Interval interval)
{
	_unions.push_back(interval);
}

/* operators */

Interval Interval::operator&&(Interval &interval)
{
	return intersects(interval);
}

Interval Interval::operator||(Interval &interval)
{
	return unite(interval);
}

/* methods */

bool Interval::contains(float number,bool closedInterval)
{
	bool test;
	if(closedInterval)
	{
		test = ((_start <= number) && (number <= _end));
	}
	else
	{
		test = ((_start < number) && (number < _end));
	}
	for(unsigned int i = 0;_unions.size();i++)
	{
		if(test)
		{
			return true;
		}
		test = _unions[i].contains(number,closedInterval);
	}
	return false;
}

bool Interval::isEmpty()
{
	return (_start == _end);
}

Interval Interval::intersects(Interval &interval)
{
	Interval newInterval(0,0);
	
	return newInterval;
}

Interval Interval::unite(Interval &interval)
{
	Interval newInterval(_start,_end);
	newInterval.setUnions(_unions);
	newInterval.addUnion(interval);
	return newInterval;
}