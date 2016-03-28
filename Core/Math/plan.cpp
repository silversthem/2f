#include "Plan.hpp"
#include "../Objects/Object.hpp"

Plan::Plan()
{
	_width = 0;
	_height = 0;
}

Plan::Plan(int width, int height) : _width(width),_height(height)
{
	
}

/* Adders */

void Plan::addObject(Object *o)
{
	o->onInit();
	_objects.push_back(o);
}

/* Getters */

Objects Plan::objectsInBounds(sf::FloatRect const& rect,Object *self)
{
	Objects inBounds;
	Objects::iterator it = _objects.begin();
	for(;it != _objects.end();it++)
	{
		if((*it)->getBounds().intersects(rect))
		{
			if(*it != NULL && *it != self)
			{
				inBounds.push_back(*it);
			}
		}
	}
	return inBounds;
}

Objects Plan::objectsTouching(Object* object,sf::Vector2f const& projection)
{
	Objects touching = objectsInBounds(Plan::projectRectangle(object->getBounds(),projection),object);
	Objects::iterator it = touching.begin();
	for(;it != touching.end();)
	{
		if(!(*it)->collision(object,projection))
		{
			touching.erase(it);
		}
		else
		{
			it++;
		}
	}
	return touching;
}

Objects Plan::projectionTouching(Object* object,sf::Vector2f const& projection)
{
	Objects willTouch = objectsTouching(object,projection);
	Objects::iterator it = willTouch.begin();
	for(;it != willTouch.end();)
	{
		if((*it)->collision(object)) // Objects being touched, we don't care about them
		{
			willTouch.erase(it);
		}
		else
		{
			it++;
		}
	}
	return willTouch;
}

/* Setters */

void Plan::setBounds(int width,int height)
{
	_width = width;
	_height = height;
}

/* Testers */

bool Plan::isInBounds(Object* object,sf::Vector2f const& projected)
{
	return Plan::inBounds(Plan::projectRectangle(object->getBounds(),projected),sf::FloatRect(sf::Vector2f(0,0),sf::Vector2f(_width,_height)));
}

/* Methods */

void Plan::calculateAll() // Does calculations for every object
{
	
}

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

sf::FloatRect Plan::projectRectangle(sf::FloatRect rect,sf::Vector2f const& project)
{
	rect.top += project.y;
	rect.left += project.x;
	return rect;
}

/* Static Calculations With Convexes shapes */

