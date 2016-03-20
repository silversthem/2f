#ifndef TOWARD_HPP
#define TOWARD_HPP

#include "Movement.hpp"
#include "Along.hpp"

/* A movement towards a point */

class Toward : public Along
{
protected:
	const sf::Vector2f* _point; // The point
public:
	Toward();
	Toward(sf::Vector2f const& point,float const& angle = 0); // Creates a "toward" movement
	/* Setters */
	void toward(sf::Vector2f const& point); // Sets point
	/* Getters */
	sf::Vector2f getPoint(); // Returns the point
	sf::Vector2f getMovement(sf::Vector2f const& position,float const& speed); // Returns the movement
};

#endif