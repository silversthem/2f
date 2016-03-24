#ifndef PLAN_HPP_INCLUDED
#define PLAN_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Interval.hpp"
#include "Geometry/Line.hpp"

/* A plan in which there's objects */

class Object; // Declaration to avoid conflicts

typedef std::vector<Object*> Objects; // Array of objects

class Plan
{
protected:
	Objects _objects; // Objects in plan
	// Structures
	// Projectiles
	// Timer
	int _width,_height; // Plan bounds, starts at (0,0)
public:
	Plan(); // Creates a plan
	Plan(int width, int height); // Creates a boundede plan
	/* Getters */
	Objects objectsInBounds(sf::FloatRect const& rect,Object *self = NULL); // Get objects in a rectangle
	Objects objectsTouching(Object const& object); // Gets objects touching an object
	// Structures
	/* Setters */
	void setBounds(int width,int height); // Sets bounds
	/* Methods */
	// do calculations for objects, projectiles & structures
	// Shoot a projectile
	// Delete an object from the plan
	// Pathfind through structures
	/* Time related */
	// Tick items (objects and else)
	// Tick forces
	/* Static Calculations with box */
	static bool inBounds(sf::FloatRect const& rect1,sf::FloatRect const& rect2,bool reversed = false); // if a box interacts with another
	static bool inside(sf::FloatRect const& container,sf::FloatRect const& containee); // If the box is fully inside the other
	/* Static Calculations with convexes shapes */
	// In
	// Touching
};

#endif