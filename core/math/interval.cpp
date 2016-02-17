#include "interval.hpp"

using namespace Math;

Interval::Interval()
{
	clear();
}

Interval::Interval(float number)
{
	_interval.Start.Excluded = _interval.End.Excluded = false;
	_interval.Start = _interval.End = 0;
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
	i.Start = 0;
	i.End = -1;
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

void Interval::setUnions(std::vector<F2::Interval> unions)
{
	_unions = unions;
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

void Interval::clear()
{
	F2::Interval i;
	i.Start = i.End = 0;
	i.Start.Excluded = i.End.Excluded = true;
	_interval = i;
	_unions.clear();
}

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
			if(_interval.Start != _unions[i].Start) // not same value : not unique
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

bool Interval::isContinous()
{
	
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

Interval Interval::intersect(F2::Interval interval)
{
	Interval intersection;
	
	return intersection.getInterval();
}

Interval Interval::intersect(Math::Interval interval)
{
	Interval intersection;
	
	return intersection.getInterval();
}

void Interval::fuse()
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
		if(interval.Start == interval.End)
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
		if(interval.Start >= interval.End) // start superior or equal to end = empty
		{
			return false;
		}
	}
	else
	{
		if(interval.Start > interval.End) // start superior to end = empty
		{
			return false;
		}
	}
	return true;
}

bool Interval::isContinous(F2::Interval i1,F2::Interval i2)
{
	if(i1.End >= i2.Start)
	{
		if(i1.End <= i2.Start)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(i2.End <= i1.Start)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Interval::contains(F2::Interval interval,float number)
{
	if(interval.Start.Excluded) // don't count start
	{
		if(interval.Start >= number) // below or equal to start
		{
			return false;
		}
	}
	else
	{
		if(interval.Start > number) // below to start
		{
			return false;
		}
	}
	if(interval.End.Excluded) // don't count end
	{
		if(interval.End <= number) // superior or equal to end
		{
			return false;
		}
	}
	else
	{
		if(interval.End < number) // superior to end
		{
			return false;
		}
	}
	return true;
}

bool Interval::contains(F2::Interval container,F2::Interval test)
{
	if(container.Start <= test.Start)
	{
		if(container.End >= test.End)
		{
			return true;
		}
	}
	return false;
}

Interval Interval::fuse(F2::Interval i1,F2::Interval i2)
{
	Interval i;
	if(Interval::isContinous(i1,i2)) // they are fusable
	{
		if(i1.Start > i2.Start)
		{
			i.setStart(i2.Start);
		}
		else
		{
			i.setStart(i1.Start);
		}
		if(i1.End > i2.End)
		{
			i.setEnd(i1.End);
		}
		else
		{
			i.setStart(i2.End);
		}
	}
	else
	{
		i.clear(); // empty interval
	}
	return i;
}

F2::Interval Interval::intersect(F2::Interval i1,F2::Interval i2)
{
	F2::Interval i3;
	if(i1.Start >= i2.Start) // intersection [i1.Start;?]
	{
		if(i1.Start <= i2.End)
		{
			i3.Start = i1.Start;
			if(i1.End >= i2.End) // intersection [i1.Start;i2.End]
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
			i3.Start = i3.End = 0; // creating empty interval then
			i3.Start.Excluded = i3.End.Excluded = true;
		}
	}
	else
	{
		if(i2.Start <= i1.End) // intersection [i2.Start;?]
		{
			i3.Start = i2.Start;
			if(i2.End >= i1.End) // intersection [i2.Start;i1.End]
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
			i3.Start = i3.End = 0; // creating empty interval then
			i3.Start.Excluded = i3.End.Excluded = true;
		}
	}
	return i3;
}
// end file