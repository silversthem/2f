#include <iostream>

/* 2f files */
#include "include/2f/2f.hpp"

/* Example files */

class Rect : public F2::Rectangle
{
public:
	Rect(sf::Vector2f const& pos)
	{
		setPosition(pos);
		setSize(sf::Vector2f(20,20));
		setFillColor(sf::Color::Yellow);
	}
	void onKeyPressed(sf::Event::KeyEvent const& key)
	{
		move(5,5);
	}
};

class Frame : public F2::Frame
{
protected:
	Rect *_r;
public:
	Frame(Rect *r)
	{
		frame(200,200,"test");
		_r = r;
		Frame::addObject(r);
	}
	void onDisplay()
	{
		if(_r != 0 && _r->getObjectPosition().x == 100)
		{
			_r->deletion();
			_r = 0;
		}
	}
};

int main()
{
	/* Tests */
	Rect r(sf::Vector2f(20,20));
	Frame f(&r);
	f.run();
	return 0;
}