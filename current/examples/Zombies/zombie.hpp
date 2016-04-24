/*
 * Tile/Sprite/Entity test
 */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "../../include/2f/2f.hpp"

class Zombie : public F2::Tile
{
protected:
	sf::Vector2f _size;
public:
	Zombie() : _size(100,100)
	{
		set_texture_from_file("Ressources/sprites.jpg");
		setPosition(0,0);
		setTextureRect(sf::IntRect(0,0,_size.x,_size.y));
	}
	sf::Vector2f getMiddle(sf::Vector2f const& pos)
	{
		return sf::Vector2f(pos.x - (_size.x/2),pos.y - (_size.y/2));
	}
	void mouseMoved(sf::Vector2f const& pos)
	{
		setTextureRect(sf::IntRect(pos.x - (_size.x/2),pos.y - (_size.y/2),_size.x,_size.y));
		setPosition(getMiddle(pos));
	}
};

void test()
{
	F2::Frame f(600,600,"Zombies");

	F2::Layer<Zombie> zombies;
	f.add_layer<Zombie>("Zombies",&zombies);

	Zombie z; // Adding a zombie
	zombies.add(&z);

	f.run();
}

#endif