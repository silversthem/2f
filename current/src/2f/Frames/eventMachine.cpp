#include "../../../include/2f/Frames/EventMachine.hpp"

F2::EventMachine::EventMachine()
{
	
}

/* Adders */

void F2::EventMachine::addListener(Listener* l)
{
	l->connect();
	_listeners.push_back(l);
}

/* Methods */

void F2::EventMachine::handle()
{
	VECTOR_OF(F2::Listener)::iterator it = _listeners.begin();
	for(;it != _listeners.end();)
	{
		if((*it)->isDeleting())
		{
			_listeners.erase(it);
			(*it)->disconnect();
		}
		else
		{
			call(*it);
			it++;
		}
	}
}

void F2::EventMachine::close()
{
	VECTOR_OF(F2::Listener)::iterator it = _listeners.begin();
	for(;it != _listeners.end();)
	{
		if((*it)->isDeleting())
		{
			_listeners.erase(it);
			(*it)->disconnect();
		}
		else
		{
			(*it)->onClose();
			it++;
		}
	}
}

/* Protected Methods */

void F2::EventMachine::call(Listener* l)
{
	switch(_event.type)
	{
		case sf::Event::KeyPressed: // Key pressed
			l->onKeyPressed(_event.key);
		break;
		case sf::Event::KeyReleased: // Key released
			l->onKeyReleased(_event.key);
		break;
		case sf::Event::MouseButtonPressed: // Mouse click
			l->onMouseClicked(_event.mouseButton);
		break;
		case sf::Event::MouseButtonReleased: // Mouse released
			l->onMouseReleased(_event.mouseButton);
		break;
		case sf::Event::MouseMoved: // Mouse move
			l->onMouseMoved(_event.mouseMove);
		break;
		default:
			onEvent(); // Unhandled event, yet
		break;
	}
}

void F2::EventMachine::onEvent()
{
	
}