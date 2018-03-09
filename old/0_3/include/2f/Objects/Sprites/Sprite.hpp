/*
 * A sprite is a textured rectangle, like a tile.
 * However, sprites can store multiple texture and switch easily between them.
 */

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
/* 2f */
#include "../MovingObject.hpp"

namespace F2
{
	typedef std::pair<sf::Texture*,sf::IntRect> SpritePair; // Easy pair to switch between textures

	class Sprite : public MovingObject, public sf::Sprite
	{
	protected:
		std::map<std::string,SpritePair> _textures; // Possible textures for the sprite
	public:
		 Sprite(); // Creates a sprite
		/* Adders */
		void add_texture(std::string const& name,SpritePair const& pair); // Adds a possible texture for the sprite
		/* Setters */
		void sprite(std::string const& name); // Sets the current sprite
		/* Object Getters */
		virtual const sf::Drawable& getDrawable(); // Returns the tile, ready to be drawn
		const sf::Vector2f&   getObjectPosition(); // Gets object position in plan
		sf::FloatRect   getObjectBounds(); // Gets object boundaries
		/* Collision */
		bool isIn(sf::Vector2f const& point); // If a point is in object
		bool touches(Object *o); // If an object touches this one
		/* Static methods */
		static SpritePair pair(sf::Texture &t,sf::IntRect const& rect); // Creates a pair for the sprite
	};
};

#endif