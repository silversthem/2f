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
	/* Events */
	void onInit();
	virtual void display(); // When displaying
	void onDisplay();
	/* Collisions */
	virtual bool isIn(sf::Vector2f const& point); // If a point is in the rectangle
	virtual bool intersect(Line const& line); // If a line intersects the rectangle
	virtual bool collision(Object* object,bool const &reversetest = false); // If an object touches this one
};

#endif