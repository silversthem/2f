#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../MovingObject.hpp"
#include "../../Listeners/Listener.hpp"

/* Rectangle */

class Rectangle : public sf::RectangleShape, public MovingObject
{
protected:
	// Size and position
public:
	// virtual init and methods because rectangle has size, not scale
};

#endif