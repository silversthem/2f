#include "Plan.hpp"
#include "../Interval.hpp"

using namespace Math;

Plan::Plan()
{
	
}

Plan::Plan(F2::Plan plan)
{
	_plan = plan;
}

/* Getters */

F2::Plan Plan::getPlan()
{
	return _plan;
}

Objects Plan::getObjects()
{
	return _objects;
}

Physics::Object Plan::getObject(unsigned int id)
{
	if(id < _objects.size())
	{
		return *_objects[id];
	}
	throw "No object at this id";
}

/* Pointers */

F2::Plan* Plan::plan()
{
	return &_plan;
}

Objects* Plan::objects()
{
	return &_objects;
}

Physics::Object* Plan::object(unsigned int id)
{
	if(id < _objects.size())
	{
		return _objects[id];
	}
	throw "No object at this id";
}

/* Setters */

void Plan::setPlan(F2::Plan plan)
{
	_plan = plan;
}

/* Adders */

void Plan::addObject(Physics::Object &object)
{
	_objects.push_back(&object);
}

/* Methods */

Objects inLine(F2::Point start,F2::Line line)
{
	Objects in;
	// ...
	return in;
}

Objects inZone(F2::Point topLeft,F2::Point bottomRight)
{
	Objects in;
	// ...
	return in;
}