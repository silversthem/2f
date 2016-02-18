#ifndef PLAN_HPP
#define PLAN_HPP

/* A plan in which there are objects, also used for geometry calculations */

#include <vector>

#include "../../structs.hpp"
#include "../interval.hpp"

namespace Physics{ class Object; } // declaration to avoid conflits

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
		void addObject(Physics::Object const& object); // adds a object in the plan
		/* Methods */
		Objects inLine(F2::Point start,F2::Line line); // returns objects aligned
		Objects inZone(F2::Point topLeft,F2::Point bottomRight); // returns objects in a zone
		/* Static Methods */
		static bool inYRange(F2::Line line,Math::Interval Yrange); // checks if a line goes through some Y coordinates
		static bool inXRange(F2::Line line,Math::Interval Xrange); // checks if a line goes through some X coordinates
		static bool aligned(F2::Line line,F2::Position start,Physics::Object object); // checks if object is aligned with a line
		static F2::Point intersection(F2::Line f1,F2::Line f2); // gets the points if two lines are crossing each other, if they do
		static float distance(F2::Point a,F2::Point b); // get distance between two points
	};
}

#endif