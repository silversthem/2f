#include "../../../include/2f/Frames/EventMachine.hpp"
#include "../../../include/2f/Listeners/Listener.hpp"

F2::EventMachine::EventMachine()
{
	
}

/* Protected Methods */

void F2::EventMachine::handle()
{
	applyEvent(this);
}

void F2::EventMachine::applyEvent(Listener *l)
{
	switch(_event.type)
	{
		case sf::Event::KeyPressed: // Key pressed
			l->onKeyPressed(&_event);
		break;
		case sf::Event::KeyReleased: // Key released
			l->onKeyReleased(&_event);
		break;
		case sf::Event::MouseButtonPressed: // Mouse click
			l->onMouseClicked(&_event);
		break;
		case sf::Event::MouseButtonReleased: // Mouse released
			l->onMouseReleased(&_event);
		break;
		case sf::Event::MouseMoved: // Mouse move
			l->onMouseMoved(&_event);
		break;
		default:
			l->onEvent(&_event);
		break;
	}
}