#ifndef PLAN_HPP
#define PLAN_HPP

/* A plan in which there are objects, also used for geometry calculations */

#include <vector>

#include "../../structs.hpp"

namespace Physics{ class Object; } // declaration to avoid conflits

namespace Math
{
	class Interval; // declaration to avoid conflits

	class Plan
	{
	protected:
		std::vector<Physics::Object*> _objects;
		F2::Plan _plan;
	public:
		Plan(F2::Plan plan);
		/* Getters */
		std::vector<Physics::Object*>* getObjects();
		F2::Plan getPlan();
		/* Setters */
		void setPlan(const F2::Plan& plan);
		/* Adders */
		void addObject(const Physics::Object& object);
		void addObject(const Physics::Object* object);
		/* Methods */
		
		/* Static Methods */
		
	};
}

#endif