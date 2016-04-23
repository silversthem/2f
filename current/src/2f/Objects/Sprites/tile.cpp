#include "../../../../include/2f/Objects/Sprites/Tile.hpp"

F2::Tile::Tile()
{
	_dynamic = false;
	_updated = false;
	_texture = 0;
}

F2::Tile::~Tile()
{
	if(_dynamic && _texture != 0) // If the texture was dynamically allocated and still existant
	{
		delete _texture;
	}
}

/* Setters */

void F2::Tile::set_texture(sf::Texture *texture)
{
	
}

void F2::Tile::set_texture_from_file(std::string const& file)
{
	
}

void F2::Tile::set_rectangle(sf::IntRect const& r)
{
	
}

/* Getters */

const sf::Drawable& F2::Tile::getDrawable()
{
	// Configure texture if updated
	return *this;
}

sf::Texture* F2::Tile::texture(bool const& update)
{
	_updated = update;
	return _texture;
}