#include "../../../../include/2f/Objects/Shapes/Rectangle.hpp"

F2::Rectangle::Rectangle()
{
	
}

F2::Rectangle::Rectangle(sf::Vector2f const& pos,sf::Vector2f const& size,sf::Color const& color)
{
	setPosition(pos);
	setSize(size);
	setFillColor(color);
}

const sf::Vector2f& F2::Rectangle::getObjectPosition()
{
	return getPosition();
}

sf::FloatRect F2::Rectangle::getObjectBounds()
{
	return getGlobalBounds();
}

const sf::Drawable& F2::Rectangle::getDrawable()
{
	return *this;
}

bool F2::Rectangle::isIn(sf::Vector2f const& point)
{
	return getObjectBounds().contains(point);
}

bool F2::Rectangle::touches(Object *o)
{
	if(!getObjectBounds().intersects(o->getObjectBounds())) // Bounds not touching
	{
		return false;
	}
	for(int i = 0;i < 4;i++)
	{
		if(o->isIn(getPoint(i))) // If a point of the rectangle is in the object
		{
			return true;
		}
	}
	return false;
} 