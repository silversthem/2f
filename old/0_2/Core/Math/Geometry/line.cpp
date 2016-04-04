#include "Line.hpp"

Line::Line()
{
	_length = 0;
	_angle = 0;
	_isInfinite = false;
	_point1 = _point2 = 0;
}

Line::Line(float const& length,float const& angle)
{
	_length = length;
	_angle = angle;
	_isInfinite = false;
	_point1 = _point2 = 0;
}

Line::Line(sf::Vector2f const& point1,sf::Vector2f const& point2,bool store1,bool store2)
{
	if(store1)
	{
		_point1 = &point1;
	}
	else
	{
		_point1 = 0;
	}
	if(store2)
	{
		_point2 = &point2;
	}
	else
	{
		_point2 = 0;
	}
	_isInfinite = false;
	_length = Line::getDistance(point1,point2);
	_angle = Line::getAngle(point1,point2);
}

/* Getters */

float Line::angle()
{
	absolute();
	return _angle;
}

float Line::length()
{
	absolute();
	return _length;
}

/* Setters */

void Line::setLine(float const& length,float const& angle)
{
	if(!isAbsolute())
	{
		_length = length;
		_angle = angle;
	}
}

void Line::setAngle(float const& angle)
{
	if(!isAbsolute())
	{
		_angle = angle;
	}
}

void Line::setLength(float const& length)
{
	if(!isAbsolute())
	{
		_length = length;
	}
}

void Line::setInfinite(bool const& infinite)
{
	if(!isAbsolute())
	{
		_isInfinite = infinite;
	}
}


/* Testers */

bool Line::isAligned(sf::Vector2f const& point)
{
	// ...
	return false;
}

bool Line::intersect(Line const& line)
{
	// ...
	return false;
}

bool Line::overlap(Line const& line)
{
	// ...
	return false;
}

bool Line::isVertical()
{
	absolute();
	int iangle = _angle;
	return (ABS_DEG(iangle) == 90 || ABS_DEG(iangle) == 270);
}

bool Line::isAbsolute()
{
	return _point1 != 0 || _point2 != 0;
}

/* Calculations */

float Line::coefficient()
{
	absolute();
	if(!isVertical())
	{
		return 1/std::cos(RAD(_angle));
	}
	return INFINITY; // Vertical line, should have been tested. Not my problem, maybe add an exception ?
}

void Line::rotate(float const& angle)
{
	if(!isAbsolute())
	{
		_angle += angle;
	}
}

sf::Vector2f Line::applyLine(float const& number)
{
	if(length() < 1)
	{
		return sf::Vector2f(0,0);
	}
	sf::Vector2f coords;
	coords.x = std::cos(RAD(_angle)) * number; // cos(angle) = adj/hypot <=> adj = cos(angle)*hypot
	coords.y = std::sin(RAD(_angle)) * number; // sin(angle) opp/hypot <=> opp = sin(angle)*hypot
	return coords;
}

sf::Vector2f Line::intersection(Line const& line)
{
	sf::Vector2f coords;
	// ...
	return coords;
}

/* Operators */



/* Static */

float Line::getAngle(sf::Vector2f const& point1,sf::Vector2f const& point2)
{
	if(point1.x == point2.x) // Vertically aligned
	{
		if(point1.y > point2.y) // Point1 is on top
		{
			return 90;
		}
		else
		{
			return 270;
		}
	}
	else
	{
		float a = (point1.y - point2.y)/(point1.x - point2.x);
		float angle = DEG(std::acos(1/hypot(1,a)));
		if(point1.x > point2.x)
		{
			angle = 180 - angle;
		}
		if(point1.y < point2.y)
		{
			angle = 360 - angle;
		}
		return 360 - angle;
	}
}

float Line::getDistance(sf::Vector2f const& point1,sf::Vector2f const& point2)
{
	return std::sqrt(std::pow(point1.x - point2.x,2) + std::pow(point1.y - point2.y,2));
}

/* Operators */

void Line::copy(Line& line)
{
	_angle = line.angle();
	_length = line.length();
}

/* Protected */

void Line::calculateLine()
{
	if(isAbsolute()) // If line is absolute
	{
		if(_point1 != 0) // Point 1 defined
		{
			if(_point2 != 0) // Point 2 also defined
			{
				_length = Line::getDistance(*_point1,*_point2);
				_angle = Line::getAngle(*_point1,*_point2);
			}
			else // Point 1 is alone : Point 2 is (0;0)
			{
				_length = Line::getDistance(*_point1,sf::Vector2f(0,0));
				_angle = Line::getAngle(*_point1,sf::Vector2f(0,0));
			}
		}
		else if(_point2 != 0) // Only point 2 defined : Point 1 is (0;0)
		{
			_length = Line::getDistance(sf::Vector2f(0,0),*_point2);
			_angle = Line::getAngle(sf::Vector2f(0,0),*_point2);
		}
	}
}

void Line::absolute()
{
	if(isAbsolute())
	{
		calculateLine();
	}
}