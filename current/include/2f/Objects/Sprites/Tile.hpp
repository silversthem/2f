/*
 * A tile is a textured rectangle, used in structures or just to show an image segment.
 */

#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
/* 2f */
#include "../Shapes/Rectangle.hpp"

namespace F2
{
	class Tile : public Rectangle
	{
	protected:
		sf::Texture *_texture; // Tile texture
		sf::IntRect  _rect;    // Segment of texture being displayed
		bool _dynamic; // If the texture object was dynamically allocated, if so, deleting it when the tile is destroyed
		bool _updated; // If we have to update the rendering
	public:
		 Tile(); // Creates a tile
		~Tile(); // Deletes the tile
		/* Setters */
		void set_texture(sf::Texture *texture); // Gets the tile's texture
		void set_texture_from_file(std::string const& file); // Loads the texture from a file
		void set_rectangle(sf::IntRect const& r); // Sets texture segment
		/* Getters */
		virtual const sf::Drawable& getDrawable(); // Returns the tile, ready to be drawn
		sf::Texture* texture(bool const& update = true); // Gets the texture
	};
};

#endif