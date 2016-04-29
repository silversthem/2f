/*
 * A callable is a lambda function called by the eventBinder
 */

#ifndef CALLABLE_HPP
#define CALLABLE_HPP

#include <functional>
/* 2f */
#include "EventBinder.hpp"

namespace F2
{
	template <typename ArgType>
	class Callable
	{
	protected:
		std::function<void (ArgType)> _call; // The lambda to call
		EventBinder* _binder; // The lambda's event binder, to disconnect when deleted
	public:
		
	};
};

#endif