#ifndef RECTANGLE
#define RECTANGLE

#include "../Core/Core.hpp"

class TestRectangle : public Rectangle
{
protected:
	Offset left,right;
	Toward up,down;
public:
	TestRectangle(Frame &f) // creates the rectangle
	{
		connect(&f);
		setSpeed(5);
		setMaximalSpeed(5);
		up.toward(frame()->mouse());
		down.toward(frame()->mouse());
		down.setAngle(180);
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
	void onHit(Object* object)
	{
		setFillColor(sf::Color::Yellow);
	}
	void display() // When displayed
	{
		setFillColor(sf::Color::Red);
		setRotation(Line(getPosition(),frame()->mouse()).angle());
	}
};

#endif