#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>

#include "Object.hpp"

/* An object that can move and has force applied to it */

class MovingObject : public Object
{
	sf::Vector2f _speed; // Box speed
	sf::Vector2f _force; // Force applied to the moving object
	sf::Vector2f _maxSpeed; // Maximal object speed
public:
	virtual void abstract() const = 0; // no moving object instance
	/* Setters */
	/* Movements */
	// Along a line => Dot product on the line, then see
	// Towards a point => Get line from object position and point's, then see
	// Along a path => A path is a bunch of lines, usually created by a pathfinder
};

#endif