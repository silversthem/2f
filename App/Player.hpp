#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Core/Core.hpp"

class Player : public Rectangle
{
protected:
	Toward up,down; // Movement upwards and downwards
	void init()
	{
		up.toward(frame()->mouse());
		bind(sf::Keyboard::Z,up);
	}
public:
	Player(int x,int y) // Player coordinates
	{
		setPosition(sf::Vector2f(x,y));
		setFillColor(sf::Color::Red);
		setSize(sf::Vector2f(30,30));
		setSpeed(5);
	}
	void display() // When displaying the player
	{
		setRotation(Line(getPosition(),frame()->mouse()).angle());
	}
};

#endif