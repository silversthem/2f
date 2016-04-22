#include <iostream>

/* 2f files */
#include "include/2f/2f.hpp"

class Rect : public F2::Rectangle
{
protected:
	bool isAllowedToMove;
	int _speed;
	bool goingUp; // if true, going up, if false, going down
	void determineDirection()
	{
		if(getPosition().y < 0)
		{
			goingUp = false;
		}
		else if((getPosition().y + 50) >= frame()->getBounds().y)
		{
			goingUp = true;
		}
	}
public:
	Rect(int const& speed = 1,int const& x = 100,int const& y = 100)
	{
		_speed = speed;
		setPosition(sf::Vector2f(x,y));
		setFillColor(sf::Color::Blue);
		setSize(sf::Vector2f(50,50));
	}
	void init()
	{
		determineDirection();
	}
	void onTicked(int const& tick)
	{
		determineDirection();
		if(goingUp)
			move(0,-1);
		else
			move(0, 1);
	}
};

class Frame : public F2::Frame
{
protected:
	F2::Layer<Rect> _rectangles;
public:
	Frame()
	{
		frame(500,500,"Test");
		add_layer("Rectangles",&_rectangles);
		timer()->set_tick_duration(10);
		timer()->set_max_tick(100);
	}
	void mouseClicked(sf::Mouse::Button const& b,sf::Vector2f const& pos)
	{
		_rectangles.add(new Rect(1,pos.x,pos.y));
	}
	void close()
	{
		_rectangles.delete_all();
	}
};

int main()
{
	Frame f;

	f.run();

	return 0;
}