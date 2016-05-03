#include "../../../../include/2f/Objects/Sprites/Sprite.hpp"

F2::Sprite::Sprite()
{
	
}

/* Adders */

void F2::Sprite::add_texture(std::string const& name,F2::SpritePair const& pair)
{
	_textures[name] = pair;
}

/* Setters */

void F2::Sprite::sprite(std::string const& name)
{
	if(_textures.find(name) != _textures.end())
	{
		setTexture(*_textures[name].first);
		setTextureRect(_textures[name].second);
	}
}

/* Object Getters */

const sf::Vector2f& F2::Sprite::getObjectPosition()
{
	return getPosition();
}

sf::FloatRect F2::Sprite::getObjectBounds()
{
	return getGlobalBounds();
}

const sf::Drawable& F2::Sprite::getDrawable()
{
	return *this;
}

/* Object Collision */

bool F2::Sprite::isIn(sf::Vector2f const& point)
{
	return getObjectBounds().contains(point);
}

bool F2::Sprite::touches(F2::Object *o)
{
	return getObjectBounds().intersects(o->getObjectBounds());
}

/* Static methods */

F2::SpritePair F2::Sprite::pair(sf::Texture &t,sf::IntRect const& rect)
{
	return F2::SpritePair(&t,rect);
}