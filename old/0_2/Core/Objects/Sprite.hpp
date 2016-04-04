#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

/* A sprite is a sf::Sprite with collision handling */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "MovingObject.hpp"

class Sprite : public sf::Sprite, public MovingObject
{
protected:
	// frames of animation
public:
	/* Methods */
};

#endif