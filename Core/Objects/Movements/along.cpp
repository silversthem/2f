#include "Along.hpp"

Along::Along()
{
	_angle = 0;
}

Along::Along(Line const& line)
{
	_line = line;
	_angle = 0;
}

/* Getters */

sf::Vector2f Along::getMovement(sf::Vector2f const& position,float const& speed)
{
	if(_angle != 0)
	{
		_line.rotate(_angle);
	}
	return _line.applyLine(speed);
}

/* Setters */

void Along::setAngle(float const& angle)
{
	_angle = angle;
}