#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* Framework classes */
#include "Core/Core.hpp"

/* Test classes */
#include "App/TestRectangle.hpp"
#include "App/FollowingRectangle.hpp"

int main()
{
	Frame win(800,800,"Test rectangle"); // Creating a frame
	/* Test rectangle to add to the frame */
	TestRectangle r1(win);
	r1.setPosition(sf::Vector2f(100,100));
	r1.setSize(sf::Vector2f(40,20));
	r1.setFillColor(sf::Color::Red);
	/* Rectangles following the first one */
	FollowingRectangle r2(win,r1);
	r2.setPosition(sf::Vector2f(700,700));
	r2.setSize(sf::Vector2f(40,20));
	r2.setFillColor(sf::Color::Blue);
	/* Adding rectangles */
	win.addRectangle(r1);
	win.addRectangle(r2);
	win.run();
	return 0;
}