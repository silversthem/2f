#include "ObjectListener.hpp"

bool ObjectListener::mouseTouches()
{
	return _touched;
}

void ObjectListener::mouseTouched()
{
	_touched = true;
}

void ObjectListener::mouseLeft()
{
	_touched = false;
}

/* Events : all methods are empty */

void ObjectListener::onDisplay()
{
	
}

void ObjectListener::onHit(Object const& object)
{
	
}