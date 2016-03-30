#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Core/Core.hpp"
#include "MyFrame.hpp"

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
	CONNECT(MyFrame); // Connecting player to the frame
	Player(int x,int y) // Player coordinates
	{
		setPosition(sf::Vector2f(x,y));
		setFillColor(sf::Color::Red);
		setSize(sf::Vector2f(30,30));
		setSpeed(5);
	}
	void onMouseClicked(sf::Event::MouseButtonEvent const& mouse)
	{
		setPosition(frame()->mouse().x,frame()->mouse().y);
	}
	void display() // When displaying the player
	{
		setRotation(Line(getPosition(),frame()->mouse()).angle());
	}
};

#endif