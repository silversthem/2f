#include "object.hpp"
#include <cmath>

Object::Object(Position pos,Size size)
{
	setPosition(pos);
	setSize(size);
}

Object::Object(int x,int y)
{
	setPosition(x,y);
}

Object::Object(int x,int y,int w,int h)
{
	setPosition(x,y);
	setSize(w,h);
}

/* setters */

void Object::setPosition(Position position)
{
	_pos = position;
}

void Object::setPosition(int x,int y)
{
	_pos.x = x;
	_pos.y = y;
}

void Object::setSize(Size size)
{
	_size = size;
}

void Object::setSize(int w,int h)
{
	_size.w = w;
	_size.h = h;
}

void Object::setInertia(float inertia)
{
	_inertia = inertia;
}

/* getters */

Position Object::getPosition()
{
	return _pos;
}

Size Object::getSize()
{
	return _size;
}

float Object::getInertia()
{
	return _inertia;
}

Position Object::getMiddle()
{
	Position Middle;
	Middle.x = (2*_pos.x + _size.w)/2;
	Middle.y = (2*_pos.y + _size.h)/2;
	return Middle;
}

/* methods */

bool Object::isTouched(int x,int y)
{
	if(x >= _pos.x && y >= _pos.y)
	{
		if(x <= (_pos.x + _size.w) && y <= (_pos.y + _size.h))
		{
			return true;
		}
	}
	return false;
}

Line Object::getLine(Position position) // returns a Line structure of y=a*x+b type
{
	Position Middle = getMiddle();
	Line line;
	if(Middle.x - position.x == 0) // same vertical line
	{
		throw ALIGNED_VERTICALLY;
	}
	else
	{
		line.a = (Middle.y - position.y)/(Middle.x - position.x);
		line.b = Middle.y - line.a*(Middle.x);
		return line;
	}
}

Position Object::default_referencial()
{
	Position p;
	p.x = -1;
	p.y = -1;
	return p;
}

float Object::getAngle(Position position,Position Referencial)
{
	if(Referencial.x == Object::default_referencial().x && 
		Referencial.y == Object::default_referencial().y) // flat line referencial
	{
		Referencial.x = _pos.x + 1;
		Referencial.y = _pos.y;
	}
	Line l1 = getLine(Referencial);
	Line l2 = getLine(position);
	return std::acos(1/std::sqrt(l1.a*l1.a + 1)) - std::acos(1/std::sqrt(l2.a*l2.a + 1));
}

bool Object::isAligned(Object &object,Position pos2)
{
	Position Middle = object.getMiddle();
	Line f; // contains a and b of function y = a*x + b
	try
	{
		f = getLine(pos2);
	}
	catch(int const &exception)
	{
		if(exception == ALIGNED_VERTICALLY) // the object and the point are aligned vertically
		{
			if((_pos.x <= Middle.x) && (Middle.x <= (_pos.x + _size.w)))
			/* We know point and object are aligned vertically, just have to check if either is also aligned with this object */
			{
				return true;
			}
		}
		return false;
	}
	float y1,y2,x1,x2;
	y1 = f.a * _pos.x + f.b;
	y2 = f.a * (_pos.x + _size.w) + f.b;
	if((_pos.y <= y1) && (y1 <= (_pos.y + _size.h))) // crossed the first horizontal line
	{
		return true;
	}
	else if((_pos.y <= y2) && (y2 <= (_pos.y + _size.h))) // crossed the second horizontal line
	{
		return true;
	}
	if(f.a == 0) // if a is 0 and we're still there's no need to test the rest
	{
		return false;
	}
	x1 = (_pos.y - f.b)/f.a; // y = a*x + b <=> x = (y - b)/a
	x2 = (_pos.y + _size.h - f.b)/f.a;
	if((_pos.x <= x1) && (x1 <= _pos.x + _size.w)) // crossed the first vertical line
	{
		return true;
	}
	else if((_pos.x <= x2) && (x2 <= _pos.x + _size.w)) // crossed the second vertical line
	{
		return true;
	}
	return false;
}