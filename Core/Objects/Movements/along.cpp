#include "Along.hpp"

Along::Along()
{
	
}

Along::Along(Line const &line,float const& angle)
{
	_line = &line;
	_angle = angle;
}

sf::Vector2f Along::getMovement(sf::Vector2f const& position,float const& speed)
{
	if(_angle == 0)
	{
		return Plan::applyLine(*_line,speed);
	}
	return Plan::applyLine(Plan::RotateLine(*_line,_angle),speed);
}