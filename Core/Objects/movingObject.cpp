#include "MovingObject.hpp"

MovingObject::MovingObject()
{
	_movement = NULL;
	_hasMaxOffset = false;
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

void MovingObject::setMaxOffset(sf::Vector2f const& offset)
{
	_hasMaxOffset = true;
	_maxOffset = offset;
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
	if(_hasMaxOffset) // Checking if abs(x) < max.x && abs(y) < max.y
	{
		if(sum.x > _maxOffset.x)
		{
			sum.x = _maxOffset.x;
		}
		else if(sum.x < -1*_maxOffset.x)
		{
			sum.x = -1*_maxOffset.x;
		}
		if(sum.y > _maxOffset.y)
		{
			sum.y = _maxOffset.y;
		}
		else if(sum.y < -1*_maxOffset.y)
		{
			sum.y = -1*_maxOffset.y;
		}
	}
	return sum;
}