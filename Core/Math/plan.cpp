#include "Plan.hpp"
#include "../Objects/Object.hpp"



/* Getters */



/* Setters */



/* Methods */



/* Time related */



/* Static Calculations With Boxes */

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

/* Static Calculations With Convexes shapes */