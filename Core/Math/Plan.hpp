#ifndef PLAN_HPP_INCLUDED
#define PLAN_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Geometry/Line.hpp"
#include "../Objects/Object.hpp"

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
	Plan(int width, int height); // Creates a bounded plan
	/* Adders */
	void addObject(Object *o); // Adds an object to the plan
	/* Getters */
	Objects objectsInBounds(sf::FloatRect const& rect,Object *self = NULL); // Get objects in a rectangle
	Objects objectsTouching(Object* object,sf::Vector2f const& projection = sf::Vector2f(0,0)); // Gets objects touching an object
	Objects projectionTouching(Object* object,sf::Vector2f const& projection); // Gets objects only touching the projection not the actual object
	// Structures
	/* Setters */
	void setBounds(int width,int height); // Sets bounds
	/* Testers */
	virtual bool isInBounds(Object* object,sf::Vector2f const& projected = sf::Vector2f(0,0)); // If the object is in bounds
	/* Methods */
	virtual void calculateAll(); // Let objects do their calculations
	// do calculations for projectiles & structures
	// Shoot a projectile
	// Delete an object from the plan
	// Pathfind through structures
	/* Time related */
	// Tick items (objects and else)
	// Tick forces
	/* Static Calculations with box */
	static bool inBounds(sf::FloatRect const& rect1,sf::FloatRect const& rect2,bool reversed = false); // if a box interacts with another
	static bool inside(sf::FloatRect const& container,sf::FloatRect const& containee); // If the box is fully inside the other
	static sf::FloatRect projectRectangle(sf::FloatRect rect,sf::Vector2f const& project); // Gets the projection of a rectangle using a vector
	/* Static Calculations with convexes shapes */
	// In
	// Touching
};

#endif