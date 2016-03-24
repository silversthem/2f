#include "Toward.hpp"

Toward::Toward()
{
	
}

Toward::Toward(sf::Vector2f const& point)
{
	_point = &point;
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
	Line line(position,*_point);
	if(_angle != 0)
	{
		Line angleLine;
		angleLine.copy(line);
		angleLine.rotate(_angle);
		return angleLine.applyLine(speed);
	}
	return line.applyLine(speed);
}