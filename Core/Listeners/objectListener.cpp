#include "ObjectListener.hpp"

/* Mouse event track */

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

/* Physics Events : all methods are empty */

void ObjectListener::onDisplay()
{
	
}

void ObjectListener::onHit(Object *object)
{
	
}