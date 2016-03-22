#ifndef ALONG_HPP
#define ALONG_HPP

#include "Movement.hpp"
#include "../../structs.hpp"
#include "../../Math/Plan.hpp"

/* A movement along a line */

class Along : public Movement
{
protected:
	const Line* _line; // Line to follow
	float _angle; // Angle
public:
	Along();
	Along(Line const &line,float const& angle = 0); // Creates a movement along a line
	/* Getters */
	sf::Vector2f getMovement(sf::Vector2f const& position,float const& speed); // Returns movement along a line
	/* Setters */
	void setAngle(float const& angle); // Sets angle
};

#endif