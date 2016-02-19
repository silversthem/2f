#include <cmath>
#include "Object.hpp"

float distance(F2::Point a,F2::Point b) // distance between two points
{
	return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

using namespace Physics;

Object::Object()
{
	clearIntervals();
}

Object::Object(F2::Position position)
{
	_pos = position;
	clearIntervals();
}

Object::Object(F2::Position position,F2::Size size)
{
	_pos = position;
	_size = size;
	setIntervals();
}

/* Getters */

F2::Position Object::getPosition()
{
	return _pos;
}

F2::Size Object::getSize()
{
	return _size;
}

F2::Position Object::getMiddle()
{
	F2::Position middle;
	middle.x = (2*_pos.x + _size.Width)/2;
	middle.y = (2*_pos.y + _size.Height)/2;
	return middle;
}

Math::Interval Object::getXInterval()
{
	return _xInterval;
}

Math::Interval Object::getYInterval()
{
	return _yInterval;
}

F2::Position Object::getCornerPosition(Corner corner)
{
	F2::Position position = _pos;
	switch(corner)
	{
		case TopLeft: // nothing to be done here
		break;
		case TopRight:
			position.x += _size.Width;
		break;
		case BottomLeft:
			position.y += _size.Height;
		break;
		case BottomRight:
			position.x += _size.Width;
			position.y += _size.Height;
		break;
	}
	return position;
}

F2::Position Object::getCornerPosition(int corner)
{
	switch(corner)
	{
		case 1:
			return getCornerPosition(TopRight);
		break;
		case 2:
			return getCornerPosition(BottomLeft);
		break;
		case 3:
			return getCornerPosition(BottomRight);
		break;
		default:
			return getCornerPosition(TopLeft);
		break;
	}
}

/* Setters */

void Object::setPosition(F2::Position position)
{
	_pos = position;
	setIntervals();
}

void Object::setSize(F2::Size size)
{
	_size = size;
	setIntervals();
}

/* Protected Methods */

void Object::clearIntervals()
{
	_xInterval.clear();
	_yInterval.clear();
}

void Object::setIntervals()
{
	clearIntervals();
	F2::Interval_Member Xstart = {_pos.x,false};
	F2::Interval_Member Xend = {_pos.x + _size.Width,false};
	F2::Interval_Member Ystart = {_pos.y,false};
	F2::Interval_Member Yend = {_pos.y + _size.Height,false};
	_xInterval.setStart(Xstart);
	_xInterval.setEnd(Xend);
	_yInterval.setStart(Ystart);
	_yInterval.setEnd(Yend);
}

/* Methods */

bool Object::isTraversable()
{
	return true;
}

bool Object::isTouched(F2::Position position)
{
	if(_xInterval.contains(position.x))
	{
		if(_yInterval.contains(position.y))
		{
			return true;
		}
	}
	return false;
}

bool Object::isTouched(Object object)
{
	if(!_xInterval.intersect(object.getXInterval()).isEmpty())
	{
		if(!_yInterval.intersect(object.getYInterval()).isEmpty())
		{
			return true;
		}
	}
	return false;
}

bool Object::isAligned(F2::Position position,F2::Line line)
{
	if((line.x - position.x) == 0) //  vertical line
	{
		return _yInterval.contains(position.y);
		
	}
	else // random line
	{
		float a = ((line.y - position.y)/(line.x - position.x));
		if(a == 0) // horizontal line
		{
			return _xInterval.contains(position.x);
		}
		else // regular line
		{ // we try to see if the line starting from position crosses a side of the object
			float b = position.y - a*position.x;// y = a*x + b <=> b = y - a*x
			F2::Position p1,p2; // the two points in which the object could be crossed by the line
			p1.y = getCornerPosition(TopLeft).x*a + b;
			p2.y = getCornerPosition(TopRight).x*a + b;
			p1.x = (getCornerPosition(TopLeft).y - b)/a;
			p2.x = (getCornerPosition(BottomLeft).y - b)/a;
			if(isTouched(p1)) // point one touches
			{
				return true;
			}
			if(isTouched(p2)) // point two touches
			{
				return true;
			}
		}
	}
	return false;
}

bool Object::isAligned(Object object,F2::Line line)
{
	for(int i = 0;i < 4;i++)
	{
		if(isAligned(object.getCornerPosition(i),line))
		{
			return true;
		}
	}
	return false;
}

float Object::getDistance(F2::Position position)
{
	float minimum = distance(getCornerPosition(TopLeft),position);
	float tester = minimum;
	for(int i = 1;i < 4;i++)
	{
		tester = distance(getCornerPosition(i),position);
		if(tester < minimum)
		{
			minimum = tester;
		}
	}
	return minimum;
}

float Object::getDistance(Physics::Object object)
{
	float minimum = distance(getCornerPosition(TopLeft),object.getCornerPosition(TopLeft));
	float test = minimum;
	F2::Position tester;
	for(int i = 0;i < 4;i++)
	{
		tester = getCornerPosition(i);
		for(int j = 0;j < 4;j++)
		{
			test = distance(tester,getCornerPosition(j));
			if(test < minimum)
			{
				minimum = test;
			}
		}
	}
	return minimum;
}