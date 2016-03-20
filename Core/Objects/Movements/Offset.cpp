#include "Offset.hpp"

Offset::Offset(float const& x,float const& y)
{
	setOffset(x,y);
}

void Offset::setOffset(float const& x,float const& y)
{
	_offset.x = x;
	_offset.y = y;
}

sf::Vector2f Offset::getMovement(sf::Vector2f const& position,float const& speed)
{
	return _offset;
}