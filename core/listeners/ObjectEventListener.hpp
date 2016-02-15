#ifndef OBJECT_EVENT_LISTENER_HPP
#define OBJECT_EVENT_LISTENER_HPP

#include "EventListener.hpp"

namespace Physics { class MovingObject; } // declaration to avoid conflit

namespace Listeners
{
	class ObjectEventListener : Listeners::EventListener
	{
		public:
			/* Events */
			void onHit(Physics::MovingObject &object); // when hitted by another object
			void onClicked(int click); // when clicked
	};
}

#endif