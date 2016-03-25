#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* Framework classes */
#include "Core/Core.hpp"

/* Test classes */
#include "App/TestRectangle.hpp"
#include "App/FollowingRectangle.hpp"

int main()
{
	/* Test */

	Frame win(800,800,"Test rectangle"); // Creating a window
	win.setFramerateLimit(200); // "Slow" framerate to show what's going on

	TestRectangle r1(win); // Creating a controlable rectangle
	r1.setPosition(sf::Vector2f(100,100));
	r1.setSize(sf::Vector2f(40,20));
	r1.setFillColor(sf::Color::Red);

	FollowingRectangle r2(win,r1); // A blue rectangle following the first one
	r2.setPosition(sf::Vector2f(700,700));
	r2.setSize(sf::Vector2f(40,20));
	r2.setFillColor(sf::Color::Blue);

	FollowingRectangle r3(win,r1); // A Cyan rectangle following it too
	r3.setPosition(sf::Vector2f(600,600));
	r3.setSize(sf::Vector2f(40,20));
	r3.setFillColor(sf::Color::Cyan);

	win.addRectangle(r1); // Adding rectangles to the window
	win.addRectangle(r2);
	win.addRectangle(r3);

	win.run(); // Magic ! (^_^)

	return 0;
}