#ifndef PLAN_HPP_INCLUDED
#define PLAN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Geometry/Line.hpp"
#include "../Objects/Object.hpp"

/* A plan in which there's objects */

typedef std::vector<Object*> Objects;

class Plan
{
protected:
	Objects _objects; // Objects in plan
	// Structures
	// Projectiles
	// Timer
	int _width,_height; // Plan bounds, starts at (0,0)
	/* Methods */
	Objects objectsInBounds(sf::FloatRect const& rect); // Gets objects in a rectangle
	template<typename OType,class Iter> // Any type /!\ Must inherit from the Object class, else that's going to be weird
	std::vector<OType*> touching(Object *object,Iter begin,Iter end) // Checks if an object touches OType instances
	{
		std::vector<OType*> pile;
		Iter it;
		for(it = begin;it != end;it++)
		{
			if((*it)->collision(object))
			{
				pile.push_back(*it);
			}
		}
		return pile;
	}
public:
	Plan(); // Creates a plan
	Plan(int width, int height); // Creates a bounded plan
	// Structures
	/* Adders */
	virtual void addObject(Object *object); // Adds an object in the plan
	/* Setters */
	void setBounds(int width,int height); // Sets plan bounds
	/* Methods */
	// do calculations for projectiles & structures
	// Shoot a projectile
	// Delete objects from the plan
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
	/* Template methods */
	// Along a line
};

#endif