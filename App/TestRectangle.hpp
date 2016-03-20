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
	void onMouseClicked(sf::Event::MouseButtonEvent const& mouse) // on mouse click
	{
		if(mouse.button == sf::Mouse::Right) // Teleporting when pressing right button
		{
			setPosition(mouse.x,mouse.y);
		}
		else if(mouse.button == sf::Mouse::Left) // Changing to green and going faster
		{
			setFillColor(sf::Color::Green); // Changing object to green when other button pressed
			setSpeed(2);
		}
	}
	void onMouseReleased(sf::Event::MouseButtonEvent const& mouse)
	{
		if(mouse.button == sf::Mouse::Left)
		{
			setFillColor(sf::Color::Red); // Changing object to red again
			setSpeed(1);
		}
	}
	void onMouseMoved(sf::Event::MouseMoveEvent const& mouse) // Rotating object towards the mouse
	{
		setRotation(Plan::getLine(getPosition(),frame()->mouse()).angle);
	}
};

#endif