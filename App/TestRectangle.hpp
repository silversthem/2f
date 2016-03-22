#ifndef RECTANGLE
#define RECTANGLE

#include "../Core/Core.hpp"

class TestRectangle : public Rectangle
{
protected:
	Toward towardMouse;
public:
	TestRectangle(Frame &f) // creates the rectangle
	{
		connect(&f);
		setSpeed(1);
		towardMouse.toward(frame()->mouse());
		bind(sf::Keyboard::Z,towardMouse);
	}
	void onMouseClicked(sf::Event::MouseButtonEvent const& mouse) // When mouse click
	{
		setPosition(frame()->mouse());
	}
	void onMouseMoved(sf::Event::MouseMoveEvent const& mouse) // Rotating object towards the mouse
	{
		setRotation(Plan::getLine(getPosition(),frame()->mouse()).angle);
	}
};

#endif