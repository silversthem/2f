#include "MovingObject.hpp"

MovingObject::MovingObject()
{
	_movement = NULL;
	_hasMaxSpeed = false;
}

/* Events */

void MovingObject::onKeyPressed(sf::Event::KeyEvent const& key)
{
	if(_key_movements.find(key.code) != _key_movements.end())
	{
		_key_movements[key.code]->pressing();
	}
}

void MovingObject::onKeyReleased(sf::Event::KeyEvent const& key)
{
	if(_key_movements.find(key.code) != _key_movements.end())
	{
		_key_movements[key.code]->releasing();
	}
}

/* Getters */

float MovingObject::getSpeed()
{
	return _speed;
}

sf::Vector2f MovingObject::getObjectPosition()
{
	return *_position;
}

/* Setters */

void MovingObject::setObjectPosition(sf::Vector2f const& position)
{
	_position = &position;
}

void MovingObject::setSpeed(float const& speed)
{
	_speed = speed;
}

void MovingObject::setMaximalSpeed(float const& max)
{
	_maxSpeed = max;
	_hasMaxSpeed = true;
}

void MovingObject::setMovement(Movement& movement)
{
	_movement = &movement;
	_movement->setApply(true);
}

/* Adders */

void MovingObject::bind(sf::Keyboard::Key const& key,Movement& move)
{
	_key_movements[key] = &move;
}

/* Getters */

sf::Vector2f MovingObject::getMovement()
{
	sf::Vector2f sum,current;
	sum.x = 0;
	sum.y = 0;
	std::map<sf::Keyboard::Key,Movement*>::iterator it = _key_movements.begin();
	for(;it != _key_movements.end();it++)
	{
		if(it->second->isApplying())
		{
			current = it->second->getMovement(*_position,_speed);
			sum.x += current.x;
			sum.y += current.y;
		}
	}
	if(_movement != NULL && _movement->isApplying())
	{
		current = _movement->getMovement(*_position,_speed);
		sum.x += current.x;
		sum.y += current.y;
	}
	if(_hasMaxSpeed) // Checking if abs(x) < max.x && abs(y) < max.y
	{
		if(std::abs(std::sqrt(std::pow(sum.x,2) + std::pow(sum.y,2))) > _maxSpeed)
		{
			sum.x = sum.x/std::sqrt(_maxSpeed);
			sum.y = sum.y/std::sqrt(_maxSpeed);
		}
	}
	return sum;
}