#include "../../../include/2f/Binders/EventBinder.hpp"

F2::EventBinder::EventBinder()
{
	
}

/* Protected Methods */

void F2::EventBinder::go_through(sf::Event::EventType const& etype,sf::Event *e)
{
	if(_binds.find(etype) != _binds.end()) // If there's a pile for this event
	{
		std::for_each(_binds[etype].begin(),_binds[etype].end(),[e](ActionBinder<sf::Event>* action){action->run(*e);});
	}
}

/* Adders */

void F2::EventBinder::bind(sf::Event::EventType const& etype,F2::ActionBinder<sf::Event>* action)
{
	if(_binds.find(etype) == _binds.end()) // Creating a new pile
	{
		_binds[etype] = std::vector<F2::ActionBinder<sf::Event>*>();
	}
	_binds[etype].push_back(action); // Adding to the pile
}

/* Key events */

void F2::EventBinder::onKeyPressed(sf::Event *e)
{
	go_through(sf::Event::KeyPressed,e);
	F2::Listener::onKeyPressed(e);
}

void F2::EventBinder::onKeyReleased(sf::Event *e)
{
	go_through(sf::Event::KeyReleased,e);
	F2::Listener::onKeyReleased(e);
}

/* Mouse events */

void F2::EventBinder::onMouseClicked(sf::Event *e)
{
	go_through(sf::Event::MouseButtonPressed,e);
	F2::Listener::onMouseClicked(e);
}

void F2::EventBinder::onMouseReleased(sf::Event *e)
{
	go_through(sf::Event::MouseButtonReleased,e);
	F2::Listener::onMouseReleased(e);
}

void F2::EventBinder::onMouseMoved(sf::Event *e)
{
	go_through(sf::Event::MouseMoved,e);
	F2::Listener::onMouseMoved(e);
}

/* Other events */

void F2::EventBinder::onEvent(sf::Event *e)
{
	F2::Listener::onEvent(e);
}

void F2::EventBinder::onTicked(int const& tick)
{
	// @TODO : Timers
}