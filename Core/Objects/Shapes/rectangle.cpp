#include "Rectangle.hpp"

/* Events */

void Rectangle::onInit()
{
	setObjectPosition(getPosition());
}

void Rectangle::onDisplay()
{
	move(getMovement());
}