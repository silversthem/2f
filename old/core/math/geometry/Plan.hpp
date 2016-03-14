#ifndef PLAN_HPP
#define PLAN_HPP

/* A plan in which there are objects, also used for geometry calculations */

#include <vector>
#include <cmath>

#include "../../structs.hpp"
#include "../interval.hpp"
#include "../../physics/objects/Object.hpp"

typedef std::vector<Physics::Object*> Objects;

namespace Math
{
	class Plan
	{
	protected:
		F2::Plan _plan; // the plan (x;y)
		Objects _objects; // the objects in the plan
	public:
		Plan(); // creates a plan
		Plan(F2::Plan plan); // creates a plan, specifing size
		/* Getters */
		F2::Plan getPlan(); // returns plan size
		Objects getObjects(); // returns all objects
		Physics::Object getObject(unsigned int id); // return an object
		/* Pointers */
		F2::Plan* plan(); // returns pointer to plan
		Objects* objects(); // returns pointer to objects vector
		Physics::Object* object(unsigned int id); // returns pointer to an object
		/* Setters */
		void setPlan(F2::Plan plan); // sets the plan
		/* Adders */
		void addObject(Physics::Object &object); // adds a object in the plan
		/* Methods */
		Objects inLine(F2::Point start,F2::Line line); // returns objects aligned
		Objects inZone(F2::Point topLeft,F2::Point bottomRight); // returns objects in a zone
	};
}

#endif