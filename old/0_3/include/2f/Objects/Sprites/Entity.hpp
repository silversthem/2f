/*
 * An entity is a textured rectangle, like a sprite.
 * However, entities can store textures in a certain order, and display them in said order.
 * This is useful to easily animate objects.
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
/* 2f */
#include "Sprite.hpp"
#include "../MovingObject.hpp"

namespace F2
{
	class Entity : public F2::Sprite
	{
	protected:
		
	public:
		
	};
};

#endif