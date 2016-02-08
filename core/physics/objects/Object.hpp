#ifndef OBJECT_HPP
#define OBJECT_HPP

/* A basic object in the plan */

#include "../../structs.hpp"

namespace Physics
{
	class Object
	{
	protected:
		F2::Size _size;
		F2::Position _pos;
	public:
		Object();
		Object(F2::Position);
		Object(F2::Position,F2::Size);
		/* Getters */
		F2::Position getPosition();
		F2::Size getSize();
		F2::Position getMiddle();
		/* Setters */
		void setPosition(F2::Position position);
		void setSize(F2::Size size);
		/* Methods */
		bool isTouched(F2::Position); // checks if a position touches the object
		bool isTouched(Physics::Object object); // checks if objects touch eachother
		bool isAligned(F2::Position position,F2::Line line); // checks if object is aligned with a line and another point
		bool isAligned(Physics::Object object,F2::Line line); // checks if two objects are aligned with a line
		float getDistance(F2::Position position);
		float getDistance(Physics::Object object);
	};
}

#endif