#ifndef PLAN_HPP_INCLUDED
#define PLAN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

#include "../structs.hpp"
#include "Interval.hpp"

/* Static class used for linear calculations */

#define VERTICALLY_ALIGNED -1

class Plan
{
public:
	virtual void abstract() const = 0; // no plan instance
	/* Calculations */
	static float coefficient(int const& angle); // calculates linear function coefficient associated with degree angle
	static float angle(float const& coefficient); // calculates degree angle associated with linear function cofficient
	/* Point calculations */
	static float distance(sf::Vector2f const& point1,sf::Vector2f const& point2); // get distances between two points
	static Line getLine(sf::Vector2f const& point1,sf::Vector2f const& point2); // returns a line made from two points
	/* Calculations with line */ 
	static sf::Vector2f crossLines(Line const& line1,Line const& line2); // returns the point at which lines crosses eachother, if they do
	static sf::Vector2f applyLine(Line const& line,float const& number); // calculates the coordinates from 0 to a point following a line
};

#endif