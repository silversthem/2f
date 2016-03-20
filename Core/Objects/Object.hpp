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
protected:
	Frame* _Frame; // Object's frame
public:
	void connect(Frame *frame); // Connects the object to its frame
	/* Getters */
	Frame* frame(); // Returns a pointer to the frame
	/* Tests */
	bool intersect(Line const& line); // if a line intersects the object
	bool isIn(sf::Vector2f const& point); // if a point is inside an object
	bool collision(Object const& object); // if two objects collides with each other
};

#endif