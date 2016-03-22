#include "Rectangle.hpp"
#include "../../Frames/Frame.hpp"

/* Getters */

sf::FloatRect Rectangle::getBounds()
{
	return getGlobalBounds();
}

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
	sf::Vector2f mov = getMovement();
	if(frame()->isInBounds(this,mov)) // If the movement doesn't throw us out of screen, TODO : Check for structures too
	{
		move(mov);
	}
}

/* Collisions */

bool Rectangle::isIn(sf::Vector2f const& point)
{
	return getGlobalBounds().contains(getInverseTransform().transformPoint(point)); // If the rectangle bound contains the object
}

bool Rectangle::intersect(Line const& line)
{
	// TODO
	return false;
}

bool Rectangle::collision(Object* object,bool const& reversetest)
{
	for(unsigned int i = 0;i < getPointCount();i++) // Testing for every point of the rectangle
	{
		if((*object).isIn(getPoint(i))) // If one point is in the object
		{
			return true; // We're good
		}
	}
	if(!reversetest) // This object is the first to be tested
	{
		return object->collision(this,true); // Testing if one of the object's point is in the rectangle
		// Since we've already tested the other way around, reversetest = true
	}
	return false;
}