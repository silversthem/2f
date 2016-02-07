#ifndef MOVINGOBJECT_HPP
#define MOVINGOBJECT_HPP

#include "object.hpp"

class MovingObject : Object
{
	protected:
		Speed _speed;
		Speed _finalSpeed;
		Force _acceleration;
	public:
		/* Setters */
		void setSpeed(Speed speed);
		void setSpeed(float value,float angle);
		void setForce(Force force);
		void setForce(float value,float angle);
		/* Getters */
		Speed getSpeed();
		Force getForce();
		/* Methods */
		void applyForce(Force force); // Apply a force
		Position getPosition(float tick); // get ticked position
};

#endif