#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Math/Geometry/Line.hpp"
#include "../Listeners/ObjectListener.hpp"

/* An object is used for physical calculations in plan */

class Frame; // declaration to avoid conflicts

class Object : public ObjectListener
{
public:
	/* Getters */
	virtual sf::Vector2f getObjectPosition() = 0; // Returns object position
	virtual sf::Drawable* getDrawable() = 0; // returns a pointer to the thing that has to be drawn
	/* Tests */
	virtual bool intersect(Line const& line); // if a line intersects the object
	virtual bool isIn(sf::Vector2f const& point); // if a point is inside an object
	virtual bool collision(Object* object,sf::Vector2f const& projection = sf::Vector2f(0,0)); // if two objects collides with each other
	virtual bool inBounds(sf::FloatRect const& rect); // If the object is inside a rectangle
	virtual sf::FloatRect getBounds() = 0; // Returns global bounds of object
};

#endif