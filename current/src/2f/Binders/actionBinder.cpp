#include "../../../include/2f/Binders/ActionBinder.hpp"

F2::ActionBinder::ActionBinder()
{
	enable();
	_toggle = false;
	_state  = false;
}

/* Setters */

void F2::ActionBinder::set_toggle()
{
	_toggle = true;
}

void F2::ActionBinder::toggle()
{
	_state = !_state;
}

void F2::ActionBinder::enable()
{
	_enabled = true;
}

void F2::ActionBinder::disable()
{
	_enabled = false;
}

/* Methods */

void F2::ActionBinder::run(sf::Event const& event)
{
	if(_enabled) // If the movement is enabled
	{
		if(_toggle) // If we have to toggle the movement
		{
			toggle();
		}
		if((_toggle && _state) || !_toggle) // If the movement is togglable and on or not togglable
		{
			action(event);
		}
	}
}