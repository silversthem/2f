#include "Toward.hpp"

Toward::Toward()
{
	_angle = 0;
}

Toward::Toward(sf::Vector2f const& point,float const& angle)
{
	_point = &point;
	_angle = angle;
}

/* Setters */

void Toward::toward(sf::Vector2f const& point)
{
	_point = &point;
}

/* Getters */

sf::Vector2f Toward::getPoint()
{
	return *_point;
}

sf::Vector2f Toward::getMovement(sf::Vector2f const& position,float const& speed)
{
	if(_angle == 0)
	{
		return Plan::applyLine(Plan::getLine(position,*_point),speed);
	}
	return Plan::applyLine(Plan::RotateLine(Plan::getLine(position,*_point),_angle),speed); 
}