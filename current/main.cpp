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
		if(key.code == sf::Keyboard::Z)
		{
			move(sf::Vector2f(0,-5));
		}
		else if(key.code == sf::Keyboard::S)
		{
			move(sf::Vector2f(0,5));
		}
		else if(key.code == sf::Keyboard::Q)
		{
			move(sf::Vector2f(-5,0));
		}
		else if(key.code == sf::Keyboard::D)
		{
			move(sf::Vector2f(5,0));
		}
	}
};

int main()
{
	/* Tests */
	F2::Frame f(600,600,"Test");
	Rect r(sf::Vector2f(20,20));
	f.addObject(&r);
	f.run();
	return 0;
}