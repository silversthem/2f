#ifndef MOVINGOBJECT_HPP_INCLUDED
#define MOVINGOBJECT_HPP_INCLUDED

#include "Object.hpp"

namespace Physics
{
	class MovingObject : Object
	{
	protected:
		F2::Speed _speed; // object speed
		F2::Force _force; // forces applied on the object
		F2::Speed _maxSpeed; // max object speed
		float _inertia; // how much force the object will get from collision with another
		MovingObject();
		MovingObject(F2::Force force);
		MovingObject(F2::Force force,F2::Speed maxSpeed);
		/* Getters */
		F2::Speed getSpeed(); // returns speed
		F2::Force getForce(); // returns force
		F2::Speed getMaximalSpeed(); // returns maximal speed
		float getInertia(); // returns inertia
		/* Setters */
		void setSpeed(F2::Speed speed); // sets speed
		void setForce(F2::Force force); // sets force
		void setMaximalSpeed(F2::Speed maxSpeed); // sets object maximal speed
		void setInertia(float inertia); // sets inertia
		/* Methods */
		void stop(); // stops the object
		void applyForce(F2::Force force); // applies a force on the object
		void move(float time); // moves the object a certain interval of time
		void hit(Object object); // Collision with another object
		void hit(MovingObject movingObject); // Collision with another moving object
	};
}

#endif