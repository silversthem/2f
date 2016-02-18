#ifndef EVENT_LISTENER_HPP
#define EVENT_LISTENER_HPP

#include "Listener.hpp"

/* User events method */

enum Click {LeftClick,RightClick};

namespace Listeners
{
	class EventListener : Listeners::Listener
	{
		public:
		/* Events */
		void onClick(float x,float y);
		void onKeyPressed(int key);
		void onKeyReleased(int key);
	};
}

#endif