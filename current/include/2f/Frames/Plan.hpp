/*
 * A plan is the object container
 * Defined by bounds
 * Contained structures, objects, projectiles and widgets
 * Can handle everything collision related, but also aligment, distance and else
 * Contains template methods to use on your own collections
 * Also contains the pathfinding algorithm
 */

#ifndef PLAN_HPP
#define PLAN_HPP

#include <vector> // Object and others container
/* F2 */
#include "../macros.hpp"
#include "../Math/Line.hpp"
#include "../Objects/Object.hpp"

namespace F2
{
	class Plan
	{
	protected:
		sf::FloatRect _bounds; // Bounds of the plan
		VECTOR_OF(F2::Object) _objects; // Objects in plan
		/* Template calculations */
		
	public:
		/* Constructors */
		
		/* Getters */
		
		/* Static */
		
	};
};

#endif