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
			line.angle = Plan::angle(a); // angle formed by line and linear coefficient
			line.length = Plan::distance(point1,point2);
		}
	}
	return line;
}

/* Lines */

sf::Vector2f Plan::crossLines(Line const& line1,Line const& line2)
{
	sf::Vector2f intersection;
	
	return intersection;
}

sf::Vector2f Plan::applyLine(Line const& line,float const& number)
{
	sf::Vector2f coords;
	coords.x = std::cos(RAD(line.angle)) * number; // cos(angle) = adj/hypot <=> adj = cos(angle)*hypot
	coords.y = std::sin(RAD(line.angle)) * number; // sin(angle) opp/hypot <=> opp = sin(angle)*hypot
	return coords;
}