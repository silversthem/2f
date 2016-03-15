#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Math/Plan.hpp"
#include "../Listeners/ObjectListener.hpp"
#include "../structs.hpp"

/* An object is used for physical calculations in plan */

class Frame; // declaration to avoid conflicts

class Object : public ObjectListener
{
public:
	virtual void abstract() const = 0; // no object instance
	/* Tests */
	bool intersect(Line const& line); // if a line intersects the object
	bool isIn(sf::Vector2f const& point); // if a point is inside an object
	bool collision(Object const& object); // if two objects collides with each other
	/* Static calculation */
	/* With boxes */
	// Is point in box
	// Do boxes touch each other
	// Is box aligned with line and point/box/shape
	/* With convex shapes */
	// Is point in shape
	// Do shapes touch each other
	// Is shape aligned with line and point/box/shape
};

#endif