#include "../../../include/2f/Binders/EventBinder.hpp"

F2::EventBinder::EventBinder()
{
	
}

/* Key events */

void F2::EventBinder::onKeyPressed(sf::Event *e)
{
	F2::Listener::onKeyPressed(e);
}

void F2::EventBinder::onKeyReleased(sf::Event *e)
{
	F2::Listener::onKeyReleased(e);
}

/* Mouse events */

void F2::EventBinder::onMouseClicked(sf::Event *e)
{
	F2::Listener::onMouseClicked(e);
}

void F2::EventBinder::onMouseReleased(sf::Event *e)
{
	F2::Listener::onMouseReleased(e);
}

void F2::EventBinder::onMouseMoved(sf::Event *e)
{
	F2::Listener::onMouseMoved(e);
}

/* Other events */

void F2::EventBinder::onEvent(sf::Event *e)
{
	F2::Listener::onEvent(e);
}

void F2::EventBinder::onTicked(int const& tick)
{
	
}