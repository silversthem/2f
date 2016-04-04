#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "Sprite.hpp"
#include "../Listeners/Listener.hpp"

class Entity : public Sprite
{
public:
	/* Testers */
	bool isTraversable(); // can other object go through this one
};

#endif