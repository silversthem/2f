#ifndef OBJECT_HPP
#define OBJECT_HPP

/* A basic object in a plan */

#include "../../structs.hpp"

namespace Math{ class Plan; } // declaration to avoid conflicts

namespace Physics
{
	class Object
	{
	protected:
		F2::Size _size; // object rectangle size
		F2::Position _pos; // object position
	public:
		Object(); // Creates an object
		Object(F2::Position); // Creates a object positioned
		Object(F2::Position,F2::Size); // Creates a object in the plan
		/* Getters */
		F2::Position getPosition(); // returns object position
		F2::Size getSize(); // returns object size
		F2::Position getMiddle(); // returns object size
		/* Setters */
		void setPosition(F2::Position position); // sets object position
		void setSize(F2::Size size); // sets object size
		/* Methods */
		bool isTraversable(); // if other objects are allowed to go through this one
		bool isTouched(F2::Position); // checks if a position touches the object
		bool isTouched(Physics::Object object); // checks if objects touch eachother
		bool isAligned(F2::Position position,F2::Line line); // checks if object is aligned with a line and another point
		bool isAligned(Physics::Object object,F2::Line line); // checks if two objects are aligned with a line
		float getDistance(F2::Position position); // get shortest distance between object and position
		float getDistance(Physics::Object object); // get shortest distance between two objects
	};
}

#endif