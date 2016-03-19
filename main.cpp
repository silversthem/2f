#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* Framework classes */
#include "Core/Core.hpp"

/* Test classes */
#include "App/TestRectangle.hpp"

int main()
{
	/* -- Example code -- */
	/* Creating a red test rectangle */
	TestRectangle r1;
	r1.setPosition(sf::Vector2f(100,100));
	r1.setSize(sf::Vector2f(40,20));
	r1.setFillColor(sf::Color::Red);
	/* Creating a window and adding it inside */
	Frame win(1000,1000,"Test rectangle");
	win.addRectangle(r1);
	win.run(); // Running the window
	return 0;
}