#ifndef BOX_HPP
#define BOX_HPP

#include <map>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Movements/Movement.hpp"

/* An object that can move */

class MovingObject : public Object
{
protected:
	bool _hasMaxSpeed; // If the object has a max speed
	float _speed; // Object speed
	float _maxSpeed; // Object max speed
	const sf::Vector2f* _position; // Object's position
	std::map<sf::Keyboard::Key,Movement*> _key_movements; // Movements to do when a key is pressed
	Movement *_movement; // Movement
public:
	MovingObject(); // Initializing
	/* Events */
	virtual void onKeyPressed(sf::Event::KeyEvent const& key); // When a key is pressed
	virtual void onKeyReleased(sf::Event::KeyEvent const& key); // When a key is released
	/* Getters */
	float getSpeed(); // Returns speed
	sf::Vector2f getObjectPosition(); // Returns object position
	/* Setters */
	void setObjectPosition(sf::Vector2f const& position); // Sets object position [initialization]
	void setSpeed(float const& speed); // Sets object speed
	void setMaximalSpeed(float const& max); // Sets max speed
	void setMovement(Movement& movement); // Sets object movement, independant of event
	/* Accessors */
	// To key bindings
	/* Adders */
	void bind(sf::Keyboard::Key const& key,Movement& move); // links a key to a movement
	sf::Vector2f getMovement(); // Returns offset by which to move object
};

#endif