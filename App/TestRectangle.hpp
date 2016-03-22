#ifndef RECTANGLE
#define RECTANGLE

#include "../Core/Core.hpp"

class TestRectangle : public Rectangle
{
protected:
	Offset up,left,right,down;
public:
	TestRectangle(Frame &f) // creates the rectangle
	{
		connect(&f);
		setSpeed(3);
		setMaximalSpeed(3);
		up.setOffset(0,-getSpeed());
		down.setOffset(0,getSpeed());
		left.setOffset(-getSpeed(),0);
		right.setOffset(getSpeed(),0);
		bind(sf::Keyboard::Z,up);
		bind(sf::Keyboard::S,down);
		bind(sf::Keyboard::Q,left);
		bind(sf::Keyboard::D,right);
	}
	void onMouseClicked(sf::Event::MouseButtonEvent const& mouse) // When mouse click
	{
		setPosition(frame()->mouse());
	}
	void display() // When displayed
	{
		setRotation(Plan::getLine(getPosition(),frame()->mouse()).angle);
	}
};

#endif