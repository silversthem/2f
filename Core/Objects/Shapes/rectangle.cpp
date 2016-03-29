#include "Rectangle.hpp"
#include "../../Frames/Frame.hpp"

/* Getters */

sf::FloatRect Rectangle::getBounds()
{
	return getGlobalBounds();
}

sf::Drawable* Rectangle::getDrawable()
{
	return this;
}

sf::Vector2f Rectangle::getMiddle()
{
	sf::Vector2f middle;
	// ...
	return middle;
}

/* Events */

void Rectangle::onInit()
{
	init();
	setObjectPosition(getPosition());
}

void Rectangle::onDisplay()
{
	display();
	move(getMovement());
	
}

/* Collisions */

bool Rectangle::inBounds(sf::FloatRect const& rect)
{
	return getBounds().intersects(rect);
}

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
	return false;
}