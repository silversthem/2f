#include "Rectangle.hpp"

/* Events */

void Rectangle::onInit()
{
	setObjectPosition(getPosition());
}

void Rectangle::display()
{
	
}

void Rectangle::onDisplay()
{
	display();
	move(getMovement());
}