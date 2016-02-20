#include "MovingObject.hpp"

using namespace Physics;

MovingObject::MovingObject()
{
	
}

MovingObject::MovingObject(F2::Force force)
{
	setForce(force);
}

MovingObject::MovingObject(F2::Force force,F2::Speed maxSpeed)
{
	setForce(force);
	setMaximalSpeed(maxSpeed);
}

/* Getters */

F2::Speed MovingObject::getSpeed()
{
	return _speed;
}

F2::Force MovingObject::getForce()
{
	return _force;
}

F2::Speed MovingObject::getMaximalSpeed()
{
	return _maxSpeed;
}

float MovingObject::getInertia()
{
	return _inertia;
}

/* Setters */

void MovingObject::setSpeed(F2::Speed speed)
{
	_speed = speed;
}

void MovingObject::setForce(F2::Force force)
{
	_force = force;
}

void MovingObject::setMaximalSpeed(F2::Speed maxSpeed)
{
	_maxSpeed = maxSpeed;
}

void MovingObject::setInertia(float inertia)
{
	_inertia = inertia;
}

/* Methods */

void MovingObject::stop()
{
	_speed.x = _speed.y = 0;
	_force.x = _force.y = 0;
}

void MovingObject::applyForce(F2::Force force)
{
	_force.x += force.x;
	_force.y += force.y;
}

void MovingObject::move(float time)
{
	_pos.x = time*time*_force.x + time*_speed.x + _pos.x;
	_pos.y = time*time*_force.y + time*_speed.y + _pos.y;
}

void MovingObject::hit(Object object)
{
	// ...
}

void MovingObject::hit(MovingObject movingObject)
{
	// ...
}