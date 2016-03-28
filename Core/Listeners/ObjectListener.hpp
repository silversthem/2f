#ifndef OBJECTLISTENER_HPP_INCLUDED
#define OBJECTLISTENER_HPP_INCLUDED

#include "Listener.hpp"

class Object;

class ObjectListener : public Listener
{
protected:
	bool _touched; // If the mouse touches the object
public:
	/* Mouse Events */
	bool mouseTouches(); // If the mouse touches the object
	void mouseTouched(); // When the mouse touches the object
	void mouseLeft(); // When the mouse leaves the object
	/* Physics Events */
	virtual void onDisplay(); // Called at every loop
	virtual void onHit(Object *object); // When hit by other object
	// Hit by a projectile
	// Hit a bound
	// Structure related
};

#endif