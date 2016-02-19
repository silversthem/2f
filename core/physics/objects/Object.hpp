#ifndef OBJECT_HPP
#define OBJECT_HPP

/* A basic object in a plan */

#include "../../structs.hpp"
#include "../../math/Interval.hpp"

enum Corner {TopLeft = 0,TopRight = 1,BottomLeft = 2,BottomRight = 3};

namespace Physics
{
	class Object
	{
	protected:
		F2::Size _size; // object rectangle size
		F2::Position _pos; // object position
		Math::Interval _xInterval; // object x interval
		Math::Interval _yInterval; // object y interval
		/* Protected Methods */
		void clearIntervals(); // resets intervals
		void setIntervals(); // calculates intervals
	public:
		Object(); // Creates an object
		Object(F2::Position); // Creates a object positioned
		Object(F2::Position,F2::Size); // Creates a object in the plan
		/* Getters */
		F2::Position getPosition(); // returns object position
		F2::Size getSize(); // returns object size
		F2::Position getMiddle(); // returns object size
		Math::Interval getXInterval(); // returns x interval
		Math::Interval getYInterval(); // returns y interval
		F2::Position getCornerPosition(Corner corner); // gets the position of a corner
		F2::Position getCornerPosition(int corner); // gets the position of a corner, with an int
		/* Setters */
		void setPosition(F2::Position position); // sets object position
		void setSize(F2::Size size); // sets object size
		/* Methods */
		bool isTraversable(); // if other objects are allowed to go through this one
		bool isTouched(F2::Position position); // checks if a position touches the object
		bool isTouched(Physics::Object object); // checks if objects touch eachother
		bool isAligned(F2::Position position,F2::Line line); // checks if object is aligned with a line and another point
		bool isAligned(Physics::Object object,F2::Line line); // checks if two objects are aligned with a line
		float getDistance(F2::Position position); // get shortest distance between object and position
		float getDistance(Physics::Object object); // get shortest distance between two objects
	};
}

#endif