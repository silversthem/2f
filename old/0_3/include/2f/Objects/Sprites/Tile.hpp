/*
 * A tile is a textured rectangle, used in structures or just to show an image segment.
 */

#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
/* 2f */
#include "../Object.hpp"

namespace F2
{
	class Tile : public Object, public sf::Sprite
	{
	protected:
		sf::Texture* _dynamic; // If the texture was dynamically allocated for this sprite
	public:
		Tile(); // Creates a tile
		Tile(sf::Texture const& texture); // Creates a textured tile
		Tile(sf::Texture const& texture,sf::IntRect const& rect); // Creates a sized textured tile
		~Tile(); // Deletes the tile
		/* Setters */
		void set_texture_from_file(std::string const& file); // Loads the texture from a file
		/* Getters */
		virtual const sf::Drawable& getDrawable(); // Returns the tile, ready to be drawn
		const sf::Vector2f&   getObjectPosition(); // Gets object position in plan
		sf::FloatRect   getObjectBounds(); // Gets object boundaries
		/* Collision */
		bool isIn(sf::Vector2f const& point); // If a point is in object
		bool touches(Object *o); // If an object touches this one
	};
};

#endif