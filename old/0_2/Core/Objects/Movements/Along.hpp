#ifndef ALONG_HPP
#define ALONG_HPP

#include "Movement.hpp"
#include "../../Math/Plan.hpp"

/* A movement along a line */

class Along : public Movement
{
protected:
	Line _line; // Line to follow
	float _angle; // Angle to apply to line
public:
	Along(); // Default constructor
	Along(Line const& line); // Creates a movement along a line
	/* Getters */
	sf::Vector2f getMovement(sf::Vector2f const& position,float const& speed); // Returns movement along a line
	/* Setters */
	void setAngle(float const& angle); // Sets line angle
	/* Accessors */
};

#endif