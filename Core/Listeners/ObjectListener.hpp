#ifndef OBJECTLISTENER_HPP_INCLUDED
#define OBJECTLISTENER_HPP_INCLUDED

#include "Listener.hpp"

class Object;

class ObjectListener : public Listener
{
public:
	virtual void onEvent(sf::Event const& event); // basic event
	void onClicked(sf::Mouse const& mouse); // when clicked
	void onClickedReleased(sf::Mouse const& mouse); // when click released
	void onClickTouch(sf::Mouse const& mouse); // when the mouse touches the object
	void onClickLeft(sf::Mouse const& mouse); // when the mouse leaves the object 
};

#endif