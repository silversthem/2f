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
/* 2f */
#include "../Containers/Map.hpp"
#include "../macros.hpp"
#include "../Math/Line.hpp"
#include "../Objects/Object.hpp"

namespace F2
{
	/* Plan class */
	class Plan
	{
	protected:
		sf::FloatRect _bounds; // Plan bounds
		Map _stuff;            // All things, classed as you wish
	public:
		Plan();
		Plan(int const& width,int const& height);
		/* Setters */
		void setBounds(int const& width,int const& height); // Sets plan's bounds
		Map* map(); // Returns the map
	};
};

#endif