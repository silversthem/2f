#include "../../../include/2f/Frames/EventMachine.hpp"

F2::EventMachine::EventMachine()
{
	
}
/* Methods */

void F2::EventMachine::handle()
{
	
}

void F2::EventMachine::close()
{
	
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