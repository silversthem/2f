/*
 * Tile/Sprite/Entity test
 */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

/* 2f */
#include "../../include/2f/2f.hpp"

class Zombie : public F2::Sprite
{
public:
	Zombie(sf::Texture &t)
	{
		add_texture("right",F2::Sprite::pair(t,sf::IntRect(50,30,100,100))); // Adding the right foot up zombie sprite
		add_texture("left",F2::Sprite::pair(t,sf::IntRect(350,180,100,100))); // Adding the right foot up zombie sprite
		add_texture("idle",F2::Sprite::pair(t,sf::IntRect(50,170,100,100))); // Adding the idle zombie ~> doing nothing
		setPosition(100,100);
		setOrigin(50,50); // Origin as middle, for rotation
		sprite("idle"); // Selecting idle texture
		bind(sf::Event::KeyPressed,"test",[this](sf::Event *e){this->sprite("right");});
	}
	void keyPressed(sf::Keyboard::Key const& key)
	{
		
	}
	void mouseMoved(sf::Vector2f const& pos)
	{
		setRotation(90 - F2::Line(getPosition(),pos).angle()); // Orienting sprite the right way
	}
};

void test()
{
	sf::Texture t;
	t.loadFromFile("Ressources/sprites.png");

	F2::Frame f(600,600,"Zombies");

	F2::Layer<Zombie> zombies;
	f.add_layer<Zombie>("Zombies",&zombies);

	Zombie z(t); // Adding a zombie
	zombies.add(&z);

	f.run();
}

#endif