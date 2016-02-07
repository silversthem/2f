#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "core/structs.hpp"
#include "core/objects/object.hpp"

int main()
{
	sf::VertexArray square(sf::TrianglesFan,6);

	sf::RenderWindow window(sf::VideoMode(600,600),"Hello world");
	sf::Event event;
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.display();
	}
	return 0;
}
