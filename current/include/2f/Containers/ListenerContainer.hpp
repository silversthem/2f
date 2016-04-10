/*
 * A ListenerContainer is a container created especially for listeners
 * It can automatically handle connection/deconnection and handles deletion by default
 * (When a listener is being deleted, it excludes it automatically)
 */

#ifndef LISTENERCONTAINER_HPP
#define LISTENERCONTAINER_HPP

#include "Container.hpp"
#include "../Listeners/Listener.hpp"

namespace F2
{
	template <typename User>
	class ListenerContainer : public CONTAINER(Listener,User)
	{
		
	};
};

#endif