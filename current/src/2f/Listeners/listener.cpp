#include "../../../include/2f/Listeners/Listener.hpp"

F2::Listener::Listener()
{
	
}

/* Protected methods */

void F2::Listener::handle(sf::Event *e)
{
	switch(e->type)
	{
		case sf::Event::KeyPressed: // Key pressed
			keyPressed(e->key.code);
		break;
		case sf::Event::KeyReleased: // Key released
			keyReleased(e->key.code);
		break;
		case sf::Event::MouseButtonPressed: // Mouse click
			mouseClicked(e->mouseButton.button,sf::Vector2f(e->mouseButton.x,e->mouseButton.y));
		break;
		case sf::Event::MouseButtonReleased: // Mouse released
			mouseReleased(e->mouseButton.button,sf::Vector2f(e->mouseButton.x,e->mouseButton.y));
		break;
		case sf::Event::MouseMoved: // Mouse move
			mouseMoved(sf::Vector2f(e->mouseMove.x,e->mouseMove.y));
		break;
		default:
			otherEvent(e);
		break;
	}
}

/* System events */

void F2::Listener::onInit()
{
	init();
}

void F2::Listener::onClose()
{
	close();
}

void F2::Listener::onTicked(int const& tick)
{
	
}

void F2::Listener::onDisplay()
{
	
}

/* User events */

void F2::Listener::keyPressed(sf::Keyboard::Key const& key)
{
	
}

void F2::Listener::keyReleased(sf::Keyboard::Key const& key)
{
	
}

void F2::Listener::mouseClicked(sf::Mouse::Button const& b,sf::Vector2f const& pos)
{
	
}

void F2::Listener::mouseReleased(sf::Mouse::Button const& b,sf::Vector2f const& pos)
{
	
}

void F2::Listener::mouseMoved(sf::Vector2f const& pos)
{
	
}

void F2::Listener::close()
{
	
}

void F2::Listener::init()
{
	
}

void F2::Listener::otherEvent(sf::Event *e)
{
	
}