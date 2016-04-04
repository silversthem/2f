#include "Movement.hpp"

Movement::Movement()
{
	_apply = false;
	_when = Pressed;
}

bool Movement::isApplying()
{
	return _apply;
}

void Movement::pressing()
{
	if(_when == Pressed)
	{
		_apply = true;
	}
	else
	{
		_apply = false;
	}
}

void Movement::releasing()
{
	if(_when == Released)
	{
		_apply = true;
	}
	else
	{
		_apply = false;
	}
}

void Movement::setWhenApply(Apply const& a)
{
	_when = a;
}

void Movement::setApply(bool const& a)
{
	_apply = a;
}

sf::Vector2f Movement::getMovement(sf::Vector2f const& position,float const& speed)
{
	sf::Vector2f v;
	v.x = 0;
	v.y = 0;
	return v;
}