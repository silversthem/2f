#ifndef PONG_HPP
#define PONG_HPP

/* This is a pong game using 2f. Also the first unit test ever written */

#include "../../include/2f/2f.hpp"

class Rectangle : public F2::Rectangle // The player controlled rectangle
{
	void onInit()
	{
		setSize(sf::Vector2f(20,40));
		setFillColor(sf::Color::White);
		setPosition(sf::Vector2f());
		setSpeed(10);
		Register("up",new F2::Movement::Offset(0,-1),sf::Keyboard::Z); // Up motion
		Register("down",new F2::Movement::Offset(0,1),sf::Keyboard::S); // Down motion
	}
};

class Ball : public F2::Projectile<F2::Circle> // The ball
{
protected:
	int hp; // The amounts of times we've lost
public:
	void onInit()
	{
		hp = 10; // We start with 10 lives
		Shape.setRadius(10); // By default the drawable is a circle
		Shape.setFillColor(sf::Color::White); // Setting its color
		setSpeed(5); // Ball speed
		setTrajectory(sf::Vector2f(-1,0)); // Moving left, the offset doesn't matter, only the speed does
	}
	void Die() // Return to original position
	{
		hp--;
		setPosition(sf::Vector2f(100,100));
	}
	void Bounce() // Bouncing of something
	{
		if(angle() == 0)
		{
			b.trajectory()->setAngle(20);
		}
		else
		{
			b.trajectory()->setAngle(ABS_DEG(180 - b.trajectory().angle()));
		}
	}
	void onFrameBoundTouched(Bound const& b) // When touching a bound of the frame
	{
		if(b == LEFT)
		{
			Die();
		}
		else
		{
			Bounce();
		}
	}
};

class Pong : public F2::Frame
{
protected:
	Player p;
	Ball b;
public:
	Pong() // Creating a pong game
	{
		frame(200,200,"Pong game");
	}
	void onInit() // Initializing before anything
	{
		p.setPosition(sf::Vector2f(0,20));
		b.setPosition(sf::Vector2f(100,100));
		addObject(p);addObject(b);
	}
	void onDisplay() // At each display
	{
		if(b.touches(p))
		{
			Bounce();
		}
		if(touchesBound(p) == UP)
		{
			p["up"]->disable();
		}
		else if(touchesBound(p) == DOWN)
		{
			p["down"]->disable();
		}
		else
		{
			p.enableAll(); // Allowing all motions
		}
	}
};

#endif