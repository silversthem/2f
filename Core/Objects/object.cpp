#include "Object.hpp"

void Object::init(sf::Transformable *element)
{
	_element = element;
	_speed = 0;
	_plan = 0;
}

/* Setters */

void Object::setSpeed(float const& speed)
{
	_speed = speed;
}

void Object::setPlan(Frame *plan)
{
	_plan = plan;
}

/* Movements */

void Object::move(sf::Vector2f const& point)
{
	_element->move(Plan::applyLine(Plan::getLine(_element->getPosition(),point),_speed));
}

/* Calculations */

bool isIn(sf::Vector2f const& point)
{
	
	return false;
}

bool collision(Object const& object)
{
	
	return false;
}