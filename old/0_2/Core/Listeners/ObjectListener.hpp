#ifndef OBJECTLISTENER_HPP_INCLUDED
#define OBJECTLISTENER_HPP_INCLUDED

#include "Listener.hpp"

class Frame; // Declaration to avoid conflicts

class ObjectListener : public Listener
{
protected:
	bool _touched; // If the mouse touches the object
	/* Overridable events -> are called by their equivalent onX event, when base class handles it fine */
	virtual void display(); // Called in the beginning of the OnDisplay method
	virtual void init(); // Called by the onInit method
public:
	/* Mouse Events */
	bool mouseTouches(); // If the mouse touches the object
	void mouseTouched(); // When the mouse touches the object
	void mouseLeft(); // When the mouse leaves the object
	/* Physics Events */
	virtual void onDisplay(); // Called at every loop
};

#endif