#include "Listener.hpp"

void Listener::onInit()
{
	
}

void Listener::ticked(float tick)
{
	
}

void Listener::onDelete()
{
	
}

/* Mouse Events */

void Listener::onMouseClicked(sf::Event::MouseButtonEvent const& mouse)
{
	
}

void Listener::onMouseReleased(sf::Event::MouseButtonEvent const& mouse)
{
	
}

void Listener::onMouseMoved(sf::Event::MouseMoveEvent const& mouse)
{
	
}

/* Key Events */

void Listener::onKeyPressed(sf::Event::KeyEvent const &key)
{
	keyPressed(key);
}

void Listener::onKeyReleased(sf::Event::KeyEvent const &key)
{
	keyReleased(key);
}

/* Protected : Overridable events */

void Listener::keyPressed(sf::Event::KeyEvent const &key)
{
	
}

void Listener::keyReleased(sf::Event::KeyEvent const &key)
{
	
}