#ifndef OFFSET_HPP
#define OFFSET_HPP

#include "Movement.hpp"

/* A movement that moves the given object by a certain offset */

class Offset : public Movement
{
protected:
	sf::Vector2f _offset; // Offset by which to move
public:
	Offset(float const& x,float const& y); // Creates an offset movement
	void setOffset(float const& x,float const& y); // Sets offset
	sf::Vector2f getMovement(sf::Vector2f const& position,float const& speed); // Gets offset
};

#endif