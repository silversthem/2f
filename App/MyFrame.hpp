#ifndef MYFRAME_HPP
#define MYFRAME_HPP

/* Test frame */

#include "../Core/Core.hpp"

USE(Enemy);
USE(Player);

class MyFrame : public Frame
{
protected:
	Player *_player; // The rectangle controllable
	VECTOR_OF(Enemy) _enemies; // Rectangles following the player rect
	std::vector<sf::Vector2f> _spawnPoints; // Where the enemies can spawn
	unsigned int _lastSpawn; // What was the last spawn point used
	/* Methods */
	sf::Vector2f getSpawnPoint(); // Gets the spawn point for an enemy
	INIT_CONNECTION(MyFrame) // Starts a connection
public:
	SET_CONNECTION(MyFrame) // Creates a way of connecting the frame to objects
	MyFrame(float const &width,float const &height,std::string const &title); // Creating a frame
	void setPlayer(Player &player); // Sets the player
	void addSpawnPoint(int x,int y);
	void addEnemy(); // Adds an enemy in the plan
	VECTOR_OF(Enemy) enemiesTouching(Object *object); // Returns the enemies that touches an object
	~MyFrame(); // Deleting enemies
};

#endif