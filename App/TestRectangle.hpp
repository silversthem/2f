#ifndef RECTANGLE
#define RECTANGLE

#include <iostream>

#include "../Core/Objects/Shapes/Rectangle.hpp"

class TestRectangle : public Rectangle
{
protected:
	int speed;
	bool moving;
	Line direction;
	sf::Vector2f mousePos;
public:
	TestRectangle() // creates the rectangle
	{
		moving = false;
		speed = 1;
	}
	void onMouseClicked(sf::Event::MouseButtonEvent const& mouse) // on mouse click
	{
		setFillColor(sf::Color::Green); // Changing object to green
	}
	void onMouseReleased(sf::Event::MouseButtonEvent const& mouse)
	{
		setFillColor(sf::Color::Red); // Changing object to red again
	}
	void onMouseMoved(sf::Event::MouseMoveEvent const& mouse) // Rotating object towards the mouse
	{
		mousePos = sf::Vector2f(mouse.x,mouse.y);
		direction = Plan::getLine(getPosition(),mousePos);
		setRotation(direction.angle);
	}
	void onKeyPressed(sf::Event::KeyEvent const& key) // When a key is pressed
	{
		if(key.code == sf::Keyboard::Z) // Moving forward
		{
			moving = true;
		}
	}
	void onKeyReleased(sf::Event::KeyEvent const& key) // When a key is released
	{
		if(key.code == sf::Keyboard::Z)
		{
			moving = false;
		}
	}
	void onDisplay() // When drawing the rectangle
	{
		if(moving) // If it's moving, moving it a little
		{
			move(Plan::applyLine(Plan::getLine(getPosition(),mousePos),speed));
		}
	}
};

#endif