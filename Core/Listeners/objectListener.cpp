#include "ObjectListener.hpp"
#include "../Frames/Frame.hpp"

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

/* Rendering events */

void ObjectListener::onDisplay()
{
	display();
}

/* Protected : Overridable events */

void ObjectListener::display()
{
	
}

void ObjectListener::init()
{
	
}