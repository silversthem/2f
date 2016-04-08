#include "../../../include/2f/Listeners/Listener.hpp"

F2::Listener::Listener()
{
	d = false;
	_connections = 0;
}

F2::Listener::~Listener()
{
	
}

void F2::Listener::deletion()
{
	d = true;
}

bool F2::Listener::isDeleting()
{
	return d;
}

void F2::Listener::connect()
{
	_connections++;
}

void F2::Listener::disconnect()
{
	_connections--;
	if(_connections == 0)
	{
		onDelete();
		delete this;
	}
}

void F2::Listener::onKeyPressed(sf::Event::KeyEvent const& key)
{
	
}

void F2::Listener::onKeyReleased(sf::Event::KeyEvent const& key)
{
	
}


void F2::Listener::onMouseClicked(sf::Event::MouseButtonEvent const& mouse)
{
	
}

void F2::Listener::onMouseReleased(sf::Event::MouseButtonEvent const& mouse)
{
	
}

void F2::Listener::onMouseMoved(sf::Event::MouseMoveEvent const& mouse)
{
	
}

void F2::Listener::onInit()
{
	
}

void F2::Listener::onTicked(float const& tick)
{
	
}

void F2::Listener::onDisplay()
{
	
}

void F2::Listener::onClose()
{
	
}

void F2::Listener::onDelete()
{
	
}