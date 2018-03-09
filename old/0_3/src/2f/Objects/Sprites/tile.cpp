#include "../../../../include/2f/Objects/Sprites/Tile.hpp"

F2::Tile::Tile()
{
	_dynamic = 0;
}

F2::Tile::Tile(sf::Texture const& texture)
{
	_dynamic = 0;
	setTexture(texture);
}

F2::Tile::Tile(sf::Texture const& texture,sf::IntRect const& rect)
{
	_dynamic = 0;
	setTexture(texture);
	setTextureRect(rect);
}

F2::Tile::~Tile()
{
	if(_dynamic != 0)
	{
		delete _dynamic;
	}
}

/* Setters */

void F2::Tile::set_texture_from_file(std::string const& file)
{
	_dynamic = new sf::Texture;
	if(!_dynamic->loadFromFile(file))
		throw 1;
	setTexture(*_dynamic);
}

/* Getters */

const sf::Drawable& F2::Tile::getDrawable()
{
	return *this;
}

const sf::Vector2f& F2::Tile::getObjectPosition()
{
	return getPosition();
}

sf::FloatRect F2::Tile::getObjectBounds()
{
	return getGlobalBounds();
}

/* Collision */

bool F2::Tile::isIn(sf::Vector2f const& point)
{
	return getObjectBounds().contains(point);
}

bool F2::Tile::touches(Object *o)
{
	// ...
	return false;
}