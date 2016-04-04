#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

//Link to MyFrame (nicely)

class Enemy : public Rectangle
{
protected:
	Toward toward;
public:
	CONNECT(MyFrame)
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
	void shouldMove(bool const& v) // Whether the enemy should win
	{
		toward.setApply(v);
	}
	float distanceToPlayer() // Distance from enemy to player
	{
		return Line(getPosition(),toward.getPoint()).length();
	}
	void display()
	{
		setRotation(Line(getPosition(),toward.getPoint()).angle());
		VECTOR_OF(Enemy) e = frame()->enemiesTouching(this); // Getting enemies touching this one
		// Handling stuff
		if(frame()->isTouchingPlayer(this)) // We're touching the player
		{
			shouldMove(false);
		}
		else if(e.size() > 0) // We're touching other enemies
		{
			if(e[0]->distanceToPlayer() > distanceToPlayer()) // The other enemy is closer
			{
				shouldMove(true);
				e[0]->shouldMove(false);
			}
			else if(e[0]->distanceToPlayer() == distanceToPlayer()) // Equal distance
			{
				shouldMove(true);
				e[0]->shouldMove(true);
			}
			else // This one is closer
			{
				shouldMove(false);
				e[0]->shouldMove(true);
			}
		}
		else // Not touching stuff, we can move
		{
			shouldMove(true);
		}
	}
};

#endif