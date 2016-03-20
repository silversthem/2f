#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../MovingObject.hpp"
#include "../../Listeners/Listener.hpp"

/* Rectangle */

class Rectangle : public sf::RectangleShape, public MovingObject
{
public:
	/* Events */
	void onInit();
	virtual void display(); // When displaying
	void onDisplay();
	/* Collisions */
};

#endif