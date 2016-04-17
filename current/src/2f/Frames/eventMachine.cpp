#include "../../../include/2f/Frames/EventMachine.hpp"
#include "../../../include/2f/Listeners/Listener.hpp"

F2::EventMachine::EventMachine()
{
	
}

/* Protected Methods */

void F2::EventMachine::init()
{
	_callstack.clear();
}

void F2::EventMachine::handle()
{
	switch(_event.type)
	{
		case sf::Event::KeyPressed: // Key pressed
			_callstack.push_back(createPair(&F2::Listener::onKeyPressed,_event));
		break;
		case sf::Event::KeyReleased: // Key released
			_callstack.push_back(createPair(&F2::Listener::onKeyReleased,_event));
		break;
		case sf::Event::MouseButtonPressed: // Mouse click
			_callstack.push_back(createPair(&F2::Listener::onMouseClicked,_event));
		break;
		case sf::Event::MouseButtonReleased: // Mouse released
			_callstack.push_back(createPair(&F2::Listener::onMouseReleased,_event));
		break;
		case sf::Event::MouseMoved: // Mouse move
			_callstack.push_back(createPair(&F2::Listener::onMouseMoved,_event));
		break;
		default:
			onEvent(); // Unhandled event
		break;
	}
}

void F2::EventMachine::applyEvent(Listener *l)
{
	
}

std::pair<void (F2::Listener::*)(const sf::Event&),sf::Event> F2::EventMachine::createPair(void (F2::Listener::*action)(const sf::Event&),sf::Event const& e)
{
	return std::pair<void (F2::Listener::*)(const sf::Event&),sf::Event>(action,e);
}

void F2::EventMachine::onEvent()
{
	
}