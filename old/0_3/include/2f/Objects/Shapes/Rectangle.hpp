/*
 * A rectangle just like its sf::RectangleShape counterpart
 * But with collisions, events and movements included
 */
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
/* 2f */
#include "../MovingObject.hpp"

namespace F2
{
	class Rectangle : public MovingObject, public sf::RectangleShape
	{
	public:
		/* Constructors */
		Rectangle(); // Creates a rectangle
		Rectangle(sf::Vector2f const& pos,sf::Vector2f const& size = sf::Vector2f(20,20),sf::Color const& color = sf::Color::Yellow);
		/* Getters */
		const sf::Vector2f& getObjectPosition(); // Gets object position in plan
		sf::FloatRect getObjectBounds();         // Gets object boundaries
		const sf::Drawable& getDrawable();       // Returns what to draw
		/* Collision */
		bool isIn(sf::Vector2f const& point);    // If a point is in object
		bool touches(Object *o);                 // If an object touches this one
	};
};

#endif