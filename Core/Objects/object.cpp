#include "Object.hpp"
#include "../Frames/Frame.hpp"

bool Object::intersect(Line const& line)
{
	return false;
}

bool Object::inBounds(sf::FloatRect const& rect)
{
	return false;
}

bool Object::isIn(sf::Vector2f const& point)
{
	return false;
}

bool Object::collision(Object* object,sf::Vector2f const& projection)
{
	return false;
}