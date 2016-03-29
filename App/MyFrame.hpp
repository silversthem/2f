#ifndef MYFRAME_HPP
#define MYFRAME_HPP

/* Test frame */

#include "Enemy.hpp"

typedef std::vector<Enemy*> Enemies; // WAAAAAAY EASIER

class MyFrame : public Frame
{
protected:
	Player *_player; // The rectangle controllable
	Enemies _enemies; // Rectangles following the player rect
	std::vector<sf::Vector2f> _spawnPoints; // Where the enemies can spawn
	unsigned int _lastSpawn; // What was the last spawn point used

	sf::Vector2f getSpawnPoint() // Gets the spawn point for an enemy
	{
		if((_lastSpawn + 1) == _spawnPoints.size())
		{
			_lastSpawn = 0;
			return _spawnPoints[0];
		}
		else
		{
			_lastSpawn++;
			return _spawnPoints[_lastSpawn];
		}
	}
public:
	MyFrame(float const &width,float const &height,std::string const &title) // Creating a frame
	{
		makeFrame(width,height,title);
		_lastSpawn = 0;
	}
	void setPlayer(Player &player) // Sets the player
	{
		_player = &player;
		addObject(&player);
	}
	void addSpawnPoint(int x,int y)
	{
		_spawnPoints.push_back(sf::Vector2f(x,y));
	}
	void addEnemy() // Adds an enemy in the plan
	{
		Enemy* e = new Enemy(getSpawnPoint());
		e->follow(_player);
		addObject(e);
		_enemies.push_back(e);
	}
	Enemies enemiesTouching(Object &object) // Returns the enemies that touches an object
	{
		return touching<Enemy,Enemies::iterator >(&object,_enemies.begin(),_enemies.end());
	}
	~MyFrame() // Deleting enemies
	{
		std::vector<Enemy*>::iterator it = _enemies.begin();
		for(;it != _enemies.end();it++)
		{
			delete *it;
		}
	}
};

#endif