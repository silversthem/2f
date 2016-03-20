#ifndef FOLLOWINGRECTANGLE
#define FOLLOWINGRECTANGLE

#include "TestRectangle.hpp"

class FollowingRectangle : public Rectangle
{
protected:
	Toward following; // Following movement
	float defaultspeed;
public:
	FollowingRectangle(Frame &frame,TestRectangle &rect,float const &speed = 0.3) // creates the rectangle
	{
		defaultspeed = speed;
		connect(&frame);
		setSpeed(speed);
		following.toward(rect.getPosition());
		setMovement(following);
	}
	void onMouseClicked(sf::Event::MouseButtonEvent const& mouse) // When clicking
	{
		if(mouse.button == sf::Mouse::Middle) // Slowing object down
		{
			setFillColor(sf::Color::Yellow);
			setSpeed(0.1);
		}
	}
	void onMouseReleased(sf::Event::MouseButtonEvent const& mouse) // When unclicking
	{
		if(mouse.button == sf::Mouse::Middle) // Normal speed back
		{
			setFillColor(sf::Color::Blue);
			setSpeed(defaultspeed);
		}
	}
	void display() // Rotating the following rectangle towards the rectangle it's following
	{
		setRotation(Plan::getLine(getPosition(),following.getPoint()).angle);
	}
};

#endif