#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Object.hpp"

class Shape : public sf::Shape, public Object
{
public:
	Shape(); // Initializes a shape
	Shape(sf::Vector2f const& position); // shape with position
};

#endif