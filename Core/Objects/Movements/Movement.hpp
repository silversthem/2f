#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

/* A movement for an object to follow
 * It gives an offset for the object to move */

#include <iostream>
#include <SFML/Graphics.hpp>

enum Apply {Pressed,Released};

class Movement
{
protected:
	bool _apply; // If the movement applies
	Apply _when; // Applying on pressing or releasing
public:
	Movement(); // Creating a movement
	void pressing(); // When pressing a key
	void releasing(); // When releasing a key
	bool isApplying(); // If the movement is applying
	void setWhenApply(Apply const& a); // Sets when the movement is applying
	void setApply(bool const& a); // Sets if the movement is applying or not
	virtual sf::Vector2f getMovement(sf::Vector2f const& position,float const& speed); // Returns movement
};

#endif