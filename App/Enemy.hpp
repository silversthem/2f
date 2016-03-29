#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

class Enemy : public Rectangle
{
protected:
	Toward toward;
public:
	Enemy(sf::Vector2f const& spawn)
	{
		setSpeed(1);
		setPosition(spawn);
		setFillColor(sf::Color::Yellow);
		setSize(sf::Vector2f(30,30));
	}
	void follow(Player *player)
	{
		toward.toward(player->getPosition());
		setMovement(toward);
	}
	void display()
	{
		setRotation(Line(getPosition(),toward.getPoint()).angle());
		// Collision
	}
};

#endif