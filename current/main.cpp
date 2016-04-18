#include <iostream>

/* 2f files */
#include "include/2f/2f.hpp"

class MyRect : public F2::Rectangle // Test class
{
	public:
	MyRect()
	{
		setPosition(20,20);
		setFillColor(sf::Color::Red);
		setSize(sf::Vector2f(40,40));
	}
};

int main()
{
	F2::Frame f(300,300,"Hi !");
	f.setFramerateLimit(2);

	MyRect r;

	f.add("my_rectangle",&r);

	f.run();

	return 0;
}