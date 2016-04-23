/*
 * Tile/Sprite/Entity test
 */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "../../include/2f/2f.hpp"

class Zombie : public F2::Tile
{
public:
	
};

void test()
{
	F2::Frame f(300,300,"Zombies");

	F2::Layer<Zombie> zombies;
	f.add_layer<Zombie>("Zombies",&zombies);

	Zombie z; // Adding a zombie
	zombies.add(&z);

	f.run();
}

#endif