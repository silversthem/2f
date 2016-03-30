#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* Framework classes */
#include "Core/Core.hpp"

/* Test classes */
#include "App/MyFrame.hpp"
#include "App/Player.hpp"
#include "App/Enemy.hpp"

int main()
{
	/* Test */

	Player p(30,30); // Player

	MyFrame win(800,800,"First test"); // Creating Window
	win.setFramerateLimit(100);

	win.addSpawnPoint(100,100); // Adding spawnpoints
	win.addSpawnPoint(500,500);
	win.addSpawnPoint(200,200);

	win.setPlayer(p);
	win.addEnemy();
	win.addEnemy();
	//win.addEnemy();

	win.run();

	return 0;
}