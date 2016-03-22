#include "Plan.hpp"

/* Calculations */

float Plan::coefficient(int const& angle)
{
	if(ABS_DEG(angle) == 90 || ABS_DEG(angle) == 270) // vertical angle : no linear function
	{
		throw VERTICALLY_ALIGNED;
	}
	return 1/std::cos(RAD(angle)); // applies the formula : cos(ANGLE) = ADJACENT/HYPOTENUSE <=> HYPOTENUSE = ADJACENT/cos(ANGLE)
}

float Plan::angle(float const& coefficient)
{
	return DEG(std::acos(1/coefficient)); // applies the formula : cos(ANGLE) = ADJACENT/HYPOTENUSE <=> ANGLE = acos(ADJACENT/HYPOTENUSE)
}

/* Points */

sf::Vector2f Plan::vector2i2f(sf::Vector2i v)
{
	sf::Vector2f vec;
	vec.x = (float) v.x;
	vec.y = (float) v.y;
	return vec;
}

float Plan::distance(sf::Vector2f const& point1,sf::Vector2f const& point2)
{
	return std::sqrt(std::pow(point1.x - point2.x,2) + std::pow(point1.y - point2.y,2));
}

Line Plan::getLine(sf::Vector2f const& point1,sf::Vector2f const& point2)
{
	Line line;
	if(point1.x == point2.x) // vertically aligned
	{
		if(point2.y > point1.y) // point 2 is higher
		{
			line.angle = 90;
			line.length = point2.y - point1.y;
		}
		else // point 1 is higher
		{
			line.angle = 270;
			line.length = point1.y - point2.y;
		}
	}
	else
	{
		if(point1.y == point2.y) // horizontally aligned
		{
			if(point2.x > point1.x) // point 2 further
			{
				line.angle = 0;
				line.length = point2.x - point1.x;
			}
			else // point 1 further
			{
				line.angle = 360;
				line.length = point1.x - point2.x;
			}
		}
		else // we need to calculate angle
		{
			float a = (point2.y - point1.y)/(point2.x - point1.x); // linear coefficient
			line.angle = Plan::angle(hypot(1,a));
			if(point1.x > point2.x)
			{
				line.angle = 180 - line.angle;
			}
			if(point1.y < point2.y)
			{
				line.angle = 180 - line.angle + 180;
			}
			line.angle = 360 - line.angle; // Inverting the angle to adapt to sfml plan
			line.length = Plan::distance(point1,point2);
		}
	}
	return line;
}

/* Lines */

sf::Vector2f Plan::crossLines(Line const& line1,Line const& line2)
{
	sf::Vector2f intersection;
	// ...
	return intersection;
}

sf::Vector2f Plan::applyLine(Line const& line,float const& number)
{
	sf::Vector2f coords;
	coords.x = std::cos(RAD(line.angle)) * number; // cos(angle) = adj/hypot <=> adj = cos(angle)*hypot
	coords.y = std::sin(RAD(line.angle)) * number; // sin(angle) opp/hypot <=> opp = sin(angle)*hypot
	return coords;
}

Line Plan::RotateLine(Line line,float const& angle)
{
	int absangle = (int) line.angle + angle;
	line.angle = ABS_DEG(absangle);
	return line;
}

/* Boxes */

bool Plan::inBounds(sf::FloatRect const& rect1,sf::FloatRect const& rect2,bool reversed)
{
	if(rect1.contains(rect2.left,rect2.top)) // Left top
	{
		return true;
	}
	else if(rect1.contains(rect2.left,rect2.top + rect2.height)) // Left bottom
	{
		return true;
	}
	else if(rect1.contains(rect2.left + rect2.width,rect2.top)) // Right top
	{
		return true;
	}
	else if(rect1.contains(rect2.left + rect2.width,rect2.top + rect2.height)) // Right bottom
	{
		return true;
	}
	if(!reversed) // Try the opposite
	{
		return Plan::inBounds(rect2,rect1,true);
	}
	return false; // No luck
}

bool Plan::inside(sf::FloatRect const& container,sf::FloatRect const& containee)
{
	if(!Plan::inBounds(container,containee)) // Not even in bound
	{
		return false;
	}
	if(container.contains(containee.left,containee.top)) // Contains top left
	{
		if(container.contains(containee.left,containee.top + containee.height)) // Contains bottom left 
		{
			if(container.contains(containee.left + containee.width,containee.top)) // Contains top right
			{
				return (container.contains(containee.left + containee.width,containee.top + containee.height)); // Contains bottom right
			}
		}
	}
	return false;
}

/* Convexe shapes */

