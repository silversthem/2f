#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Math/Plan.hpp"
#include "../Listeners/ObjectListener.hpp"
#include "../structs.hpp"

/* An object is used for physical calculations in plan */

class Frame; // declaration to avoid conflicts

struct Box // the box that's around the object
{
	sf::Vector2f min; // minimal point
	sf::Vector2f max; // maximal point
};

class Object : public ObjectListener
{
protected:
	float _speed; // object's speed
	Frame *_plan; // object's frame
	sf::Transformable *_element; // the element
public:
	void init(sf::Transformable *element); // inits object
	/* Setters */
	void setSpeed(float const& speed); // object's speed
	void setPlan(Frame *plan); // object's frame
	/* Movements */
	void move(sf::Vector2f const& point); // moves toward a point at speed
	// toward other object
	// in line
	// along path
	/* Aligments */
	// in line from point
	// in line from object
	/* Calculations */
	Box getBox(); // Returns the box containing the object
	bool intersect(Line const& line); // if a line intersects the object
	bool isIn(sf::Vector2f const& point); // if a point is inside an object
	bool collision(Object const& object); // if two objects collides with each other
};

#endif