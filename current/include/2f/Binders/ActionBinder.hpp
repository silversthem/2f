/*
 * ActionBinder is an abstract class (actually more of an interface) implemented by all binders in the event binder.
 * The action can be "togglable", meaning on a on/off switch, useful for keyEvents
 */

#ifndef ACTIONBINDER_HPP
#define ACTIONBINDER_HPP

#include <SFML/Window/Event.hpp>

namespace F2
{
	class ActionBinder
	{
	protected:
		bool _enabled; // If the binder is enabled
		bool  _toggle; // If the action can be toggled
		bool   _state; // State, if togglable
		/* Interface Methods */
		virtual void action(sf::Event const& event) = 0; // The action binded
	public:
		ActionBinder(); // Creates an ActionBinder
		/* Setters */
		void set_toggle(); // Sets toggle of the action
		void  toggle(); // Toggles the action execution
		void  enable(); // Enables binder
		void disable(); // Disables binder
		/* Methods */
		void run(sf::Event const& event); // Executes the action
	};
};

#endif