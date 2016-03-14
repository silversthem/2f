#ifndef RECTANGLE
#define RECTANGLE

#include "../Core/Objects/Shapes/Rectangle.hpp"

class TestRectangle : public Rectangle
{
public:
	TestRectangle() // creates the rectangle
	{
		Rectangle::init(this); // initializing rectangle physics
		setSpeed(5); // 5px per second
	}
	virtual void onMouseClicked(sf::Mouse const& mouse) // on mouse click
	{
		Object::move(sf::Vector2f(mouse.getPosition())); // moves object towards the mouse
	}
};

#endif