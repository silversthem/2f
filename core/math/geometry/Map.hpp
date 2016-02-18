#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

/* A Map is a plan where objects can pathfind through others and structures */

#include "Plan.hpp"

namespace Physics{ class Structure; } // declaration to avoid conflits

typedef std::vector<Physics::Structure*> Structures;

namespace Math
{
	class Map : Plan
	{
	protected:
		Structures _structs;
	public:
		/* Adders */
		void addStructure(Physics::Structure const &structure); // adds a structure to the map
		/* Methods */
	};
}

#endif