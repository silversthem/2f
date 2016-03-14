#ifndef OBJECTLISTENER_HPP_INCLUDED
#define OBJECTLISTENER_HPP_INCLUDED

#include "Listener.hpp"

class Object;

class ObjectListener : public Listener
{
public:
	void onHit(Object &object); // when hit by other object
	void onClicked(sf::Mouse const& mouse); // when clicked
	void onClickReleased(sf::Mouse const& mouse); // when click released
};

#endif