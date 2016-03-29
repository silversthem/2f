#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../MovingObject.hpp"
#include "../../Listeners/Listener.hpp"

/* Rectangle */

class Rectangle : public sf::RectangleShape, public MovingObject
{
public:
	/* Getters */
	sf::FloatRect getBounds(); // Returns bounds of the rectangle
	sf::Drawable* getDrawable(); // Returns the rectangle as a drawable
	sf::Vector2f getMiddle(); // Gets the rectangle middle point
	/* Events */
	virtual void onInit(); // Adding the rectangle in the plan
	virtual void onDisplay(); // Displaying the rectangle
	/* Collisions */
	virtual bool inBounds(sf::FloatRect const& rect); // If the object is in a rectangle
	virtual bool isIn(sf::Vector2f const& point); // If a point is in the rectangle
	virtual bool intersect(Line const& line); // If a line intersects the rectangle
	virtual bool collision(Object* object,sf::Vector2f const& projection = sf::Vector2f(0,0));
	// If an object touches this one
};

#endif