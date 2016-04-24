/*
 * An EventBinder calls methods on certain events.
 * Actions can then be combined.
 * The eventBinder overloads the onX methods from the listener class.
 * Movements, Forces and Animation in entities use binders.
 */

#ifndef EVENTBINDER_HPP
#define EVENTBINDER_HPP

#include <map>
/* 2f */
#include "../Listeners/Listener.hpp"

namespace F2
{
	class EventBinder : public Listener
	{
	protected:
		
	public:
		
	};
};

#endif