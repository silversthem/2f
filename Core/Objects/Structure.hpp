#ifndef STRUCTURE_HPP_INCLUDED
#define STRUCTURE_HPP_INCLUDED

/* A structure is a tiled collection of sprites that doesn't move */

#include <SFML/Graphics.hpp>
#include <vector>

struct Tile // a structure Tile
{
	sf::Vector2f position; // element position
	sf::Sprite* sprite; // element tile
	bool entryPoint; // if the tile lets sprite go inside the structure 
};

class Structure
{
protected:
	std::vector<sf::Vector2f> _borders; // structure borders
	std::vector<Tile> _tiles; // structure tiles
	std::vector<Tile*> _entryPoints; // Points where the player can go into
public:
	/* Adders */
	/* Methods */
	void draw(sf::RenderWindow *win); // draws structure into the window
};

#endif