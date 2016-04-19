#include "../../../include/2f/Listeners/Listener.hpp"

F2::Listener::Listener()
{
	
}

void F2::Listener::onKeyPressed(sf::Event *e)
{
	keyPressed(e->key.code);
}

void F2::Listener::onKeyReleased(sf::Event *e)
{
	keyReleased(e->key.code);
}


void F2::Listener::onMouseClicked(sf::Event *e)
{
	mouseClicked(e->mouseButton.button,sf::Vector2f(e->mouseButton.x,e->mouseButton.y));
}

void F2::Listener::onMouseReleased(sf::Event *e)
{
	mouseReleased(e->mouseButton.button,sf::Vector2f(e->mouseButton.x,e->mouseButton.y));
}

void F2::Listener::onMouseMoved(sf::Event *e)
{
	mouseMoved(sf::Vector2f(e->mouseMove.x,e->mouseMove.y));
}

void F2::Listener::onInit()
{
	
}

void F2::Listener::onTicked(int const& tick)
{
	
}

void F2::Listener::onDisplay()
{
	
}

void F2::Listener::onEvent(sf::Event *e)
{
	
}

void F2::Listener::onClose()
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