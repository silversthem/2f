#include "../../../include/2f/Frames/Plan.hpp"

/* Constructors */

F2::Plan::Plan()
{
	setBounds(0,0);
}

F2::Plan::Plan(float width,float height)
{
	setBounds(width,height);
}

/* Adders */

void F2::Plan::addObject(F2::Object *o)
{
	_objects.push_back(o);
}

/* Setters */

void F2::Plan::setBounds(float width,float height)
{
	_bounds.top    = 0;
	_bounds.left   = 0;
	_bounds.width  = width;
	_bounds.height = height;
}

/* Getters */

VECTOR_OF(F2::Object) F2::Plan::getInBounds(sf::FloatRect const& rect,F2::Object *self)
{
	VECTOR_OF(F2::Object) objects;
	VECTOR_OF(F2::Object)::iterator it = _objects.begin();
	for(;it != _objects.end();it++)
	{
		if(rect.intersects((*it)->getObjectBounds()))
		{
			if(self == NULL || self != *it)
			{
				objects.push_back(*it);
			}
		}
	}
	return objects;
}