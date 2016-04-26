/*
 * ActionBinder is an abstract class (actually more of an interface) implemented by all binders in the event binder.
 * The action can be "togglable", meaning on a on/off switch, useful for keyEvents
 */

#ifndef ACTIONBINDER_HPP
#define ACTIONBINDER_HPP

#include <SFML/Window/Event.hpp>

namespace F2
{
	template <typename ArgumentType>
	class ActionBinder
	{
	protected:
		bool _enabled; // If the binder is enabled
		bool  _toggle; // If the action can be toggled
		bool   _state; // State, if togglable
		/* Interface Methods */
		virtual void action(ArgumentType const& arg) = 0; // The action binded
	public:
		ActionBinder() // Creates an ActionBinder
		{
			_enabled = true;
			_toggle  = false;
			_state   = false;
		}
		/* Setters */
		void set_toggle(bool const& toggle = true) // Sets toggle of the action
		{
			_toggle = toggle;
		}
		void toggle() // Toggles the action execution
		{
			_state = !_state;
		}
		void enable() // Enables binder
		{
			_enabled = true;
		}
		void disable() // Disables binder
		{
			_enabled = false;
		}
		/* Methods */
		void run(ArgumentType const& arg) // Executes the action
		{
			if(_enabled)
			{
				if(_toggle)
				{
					toggle();
				}
				if((_toggle && _state) || !_toggle)
				{
					action(arg);
				}
			}
		}
	};
};

#endif