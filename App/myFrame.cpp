#include "MyFrame.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

INIT_FRAME(MyFrame); // Gets the frame ready for connection

/* Protected */

sf::Vector2f MyFrame::getSpawnPoint() // Gets the spawn point for an enemy
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

/* Public */

MyFrame::MyFrame(float const &width,float const &height,std::string const &title) // Creating a frame
{
	makeFrame(width,height,title);
	_lastSpawn = 0;
	CONNECTION(); // Connects the frame
}

void MyFrame::setPlayer(Player &player) // Sets the player
{
	_player = &player;
	addObject(&player);
}

void MyFrame::addSpawnPoint(int x,int y)
{
	_spawnPoints.push_back(sf::Vector2f(x,y));
}

void MyFrame::addEnemy() // Adds an enemy in the plan
{
	Enemy* e = new Enemy(getSpawnPoint());
	e->follow(_player);
	addObject(e);
	_enemies.push_back(e);
}

VECTOR_OF(Enemy) MyFrame::enemiesTouching(Object *object) // Returns the enemies that touches an object
{
	return touching<Enemy,VECTOR_OF(Enemy)::iterator >(object,_enemies.begin(),_enemies.end());
}

MyFrame::~MyFrame() // Deleting enemies
{
	VECTOR_OF(Enemy)::iterator it = _enemies.begin();
	for(;it != _enemies.end();it++)
	{
		delete *it;
	}
}