#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../structs.hpp"

#define ALIGNED_VERTICALLY 1

class Object // Object with hitbox
{
	protected:
		Position _pos; // Object position in plan
		Size _size; // Object size
		float _inertia; // Object inertia
	public:
		Object(int x,int y);
		Object(int x,int y,int w,int h);
		Object(Position pos,Size size);
		/* Setters */
		void setPosition(int x,int y);
		void setPosition(Position pos);
		void setSize(int w,int h);
		void setSize(Size size);
		void setInertia(float inertia);
		/* Getters */
		Position getPosition();
		Size getSize();
		float getInertia();
		Position getMiddle();
		/* Methods */
		static Position default_referencial(); // default referencial for angles, Object position.x + 1
		float getAngle(Position Otherobject,Position Referencial = Object::default_referencial());
		Line getLine(Position position);
		bool isTouched(int x,int y);
		bool isAligned(Object &object,Position pos2); // checks if this object is aligned with another object center and a point
};

#endif
