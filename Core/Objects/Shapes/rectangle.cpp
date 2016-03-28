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
	move(getMovement());
	
}

/* Collisions */

bool Rectangle::isIn(sf::Vector2f const& point)
{
	return getGlobalBounds().contains(point);
}

bool Rectangle::intersect(Line const& line)
{
	// TODO
	return false;
}

bool Rectangle::collision(Object* object,sf::Vector2f const& projection)
{
	move(projection);
	for(unsigned int i = 0;i < getPointCount();i++)
	{
		if(object->isIn(getTransform().transformPoint(getPoint(i))))
		{
			onHit(object);
			return true;
		}
	}
	move(-projection);
	return false;
}