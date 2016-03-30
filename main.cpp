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

	MyFrame win(1000,1000,"First test"); // Creating Window
	win.setFramerateLimit(100);

	win.addSpawnPoint(100,100); // Adding spawnpoints
	win.addSpawnPoint(700,100);
	win.addSpawnPoint(100,700);
	win.addSpawnPoint(700,700);

	win.setPlayer(p);
	for(int i = 0;i < 25;i++) // Adding enemies
	{
		win.addEnemy();
	}

	win.run();

	return 0;
}