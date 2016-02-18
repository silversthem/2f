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
		F2::Plan _plan;
		Objects _objects;
	public:
		/* Getters */
		/* Setters */
		/* Adders */
		/* Methods */
		/* Static Methods */
		static bool inYRange(F2::Line line,Math::Interval Yrange); // checks if a line goes through some Y coordinates
		static bool inXRange(F2::Line line,Math::Interval Xrange); // checks if a line goes through some X coordinates
		static bool aligned(F2::Line line,F2::Position start,Physics::Object object); 
		static F2::Point intersection(F2::Line f1,F2::Line f2);
		static float distance(F2::Point a,F2::Point b);
	};
}

#endif