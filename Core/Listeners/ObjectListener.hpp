#ifndef OBJECTLISTENER_HPP_INCLUDED
#define OBJECTLISTENER_HPP_INCLUDED

#include "Listener.hpp"

class Object;

class ObjectListener : public Listener
{
protected:
	bool touched; // If the mouse touches the object
public:
	virtual void onDisplay(); // Called at every loop
	virtual void onClicked(sf::Mouse const& mouse); // when clicked
	virtual void onClickedReleased(sf::Mouse const& mouse); // when click released
	virtual void onMouseTouch(sf::Mouse const& mouse); // when the mouse touches the object
	virtual void onMouseLeft(sf::Mouse const& mouse); // when the mouse leaves the object 
};

#endif