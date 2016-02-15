#include "interval.hpp"

using namespace Math;

Interval::Interval(float number)
{
	_interval.Start.Excluded = _interval.End.Excluded = false;
	_interval.Start.Value = _interval.End.Value = false;
}

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

/* Adders */

void Interval::addUnion(F2::Interval interval)
{
	_unions.push_back(interval);
}

void Interval::addUnion(Math::Interval interval)
{
	addUnion(interval.getInterval()); // adding main interval
	for(unsigned int i = 0;interval.getUnions().size();i++)
	{
		addUnion(interval.getUnion(i)); // and unions
	}
}

/* Methods */

bool Interval::isUnique()
{
	if(isEmpty())
	{
		return false;
	}
	if(!Interval::isUnique(_interval))
	{
		return false;
	}
	for(unsigned int i = 0;i < _unions.size();i++)
	{
		if(Interval::isUnique(_unions[i]))
		{
			if(_interval.Start.Value != _unions[i].Start.Value)
			{
				return false;
			}
		}
		else if(!Interval::isEmpty(_unions[i]))
		{
			return false;
		}
	}
	return true;
}

bool Interval::isEmpty()
{
	if(!Interval::isEmpty(_interval))
	{
		return false;
	}
	for(unsigned int i = 0;i < _unions.size();i++)
	{
		if(!Interval::isEmpty(_unions[i]))
		{
			return false;
		}
	}
	return true;
}

bool Interval::contains(float number)
{
	if(Interval::contains(_interval,number))
	{
		return true;
	}
	for(unsigned int i = 0;i < _unions.size();i++)
	{
		if(Interval::contains(_unions[i],number))
		{
			return true;
		}
	}
	return false;
}

bool Interval::contains(F2::Interval interval)
{
	if(!Interval::contains(_interval,interval))
	{
		return false;
	}
	for(unsigned int i = 0;i < _unions.size();i++)
	{
		if(!Interval::contains(_interval,_unions[i]))
		{
			return false;
		}
	}
	return true;
}

bool Interval::contains(Math::Interval interval)
{
	if(!contains(interval.getInterval()))
	{
		return false;
	}
	for(unsigned int i = 0;i < interval.getUnions().size();i++)
	{
		if(!contains(interval.getUnion(i)))
		{
			return false;
		}
	}
	return true;
}

F2::Interval Interval::intersect(F2::Interval interval)
{
	Interval intersection(0);
	
	return intersection.getInterval();
}

F2::Interval Interval::intersect(Math::Interval interval)
{
	Interval intersection(0);
	
	return intersection.getInterval();
}

F2::Interval Interval::fuse(F2::Interval interval)
{
	
}

Interval Interval::fuse(Interval interval)
{
	
}

/* Static methods */

bool Interval::isUnique(F2::Interval interval)
{
	if(Interval::isEmpty(interval))
	{
		return false;
	}
	if(!interval.Start.Excluded && !interval.End.Excluded)
	{
		if(interval.Start.Value == interval.End.Value)
		{
			return true;
		}
	}
	return false;
}

bool Interval::isEmpty(F2::Interval interval)
{
	if(interval.Start.Excluded || interval.End.Excluded) // one excluded
	{
		if(interval.Start.Value >= interval.End.Value) // start superior or equal to end = empty
		{
			return false;
		}
	}
	else
	{
		if(interval.Start.Value > interval.End.Value) // start superior to end = empty
		{
			return false;
		}
	}
	return true;
}

bool Interval::contains(F2::Interval interval,float number)
{
	if(interval.Start.Excluded) // don't count start
	{
		if(interval.Start.Value >= number) // below or equal to start
		{
			return false;
		}
	}
	else
	{
		if(interval.Start.Value > number) // below to start
		{
			return false;
		}
	}
	if(interval.End.Excluded) // don't count end
	{
		if(interval.End.Value <= number) // superior or equal to end
		{
			return false;
		}
	}
	else
	{
		if(interval.End.Value < number) // superior to end
		{
			return false;
		}
	}
	return true;
}

bool Interval::contains(F2::Interval container,F2::Interval test)
{
	if(container.Start.Value <= test.Start.Value)
	{
		if(container.End.Value >= test.End.Value)
		{
			return true;
		}
	}
	return false;
}

F2::Interval Interval::fuse(F2::Interval i1,F2::Interval i2)
{
	
}

F2::Interval Interval::intersect(F2::Interval i1,F2::Interval i2)
{
	F2::Interval i3;
	if(i1.Start.Value >= i2.Start.Value) // intersection [i1.Start;?]
	{
		if(i1.Start.Value <= i2.End.Value)
		{
			i3.Start = i1.Start;
			if(i1.End.Value >= i2.End.Value) // intersection [i1.Start;i2.End]
			{
				i3.End = i2.End;
			}
			else // intersection [i1.Start;i1.End]
			{
				i3.End = i1.End;
			}
		}
		else // empty intersection, the start of one is bigger than the end of the other
		{
			i3.Start.Value = i3.End.Value = 0; // creating empty interval then
			i3.Start.Excluded = i3.End.Excluded = true;
		}
	}
	else
	{
		if(i2.Start.Value <= i1.End.Value) // intersection [i2.Start;?]
		{
			i3.Start = i2.Start;
			if(i2.End.Value >= i1.End.Value) // intersection [i2.Start;i1.End]
			{
				i3.End = i1.End;
			}
			else // intersection [i2.Start;i2.End]
			{
				i3.End = i2.End;
			}
		}
		else // empty intersection
		{
			i3.Start.Value = i3.End.Value = 0; // creating empty interval then
			i3.Start.Excluded = i3.End.Excluded = true;
		}
	}
	return i3;
}