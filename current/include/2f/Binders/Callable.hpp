/*
 * A callable is a lambda function called by the eventBinder
 */

#ifndef CALLABLE_HPP
#define CALLABLE_HPP

#include <functional>

namespace F2
{
	template <typename ArgType>
	class Callable
	{
	protected:
		std::function<void (ArgType)> _call; // The lambda to call
		bool _enabled; // If the callable is enabled
	public:
		Callable(std::function<void (ArgType)> const& func) // Creates a callable
		{
			_call = func;
		}
		/* Setters */
		void enable(bool const& state = true) // Enable/Disable callable
		{
			_enabled = state;
		}
		/* Methods */
		void exec(ArgType arg) // Runs the callable
		{
			if(_enabled && _call)
			{
				_call(arg);
			}
		}
	};
};

#endif