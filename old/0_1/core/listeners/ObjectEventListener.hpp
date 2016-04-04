#ifndef OBJECT_EVENT_LISTENER_HPP
#define OBJECT_EVENT_LISTENER_HPP

#include "EventListener.hpp"

namespace Physics { class MovingObject; } // declaration to avoid conflit

enum Border {Left,Top,Bottom,Right};

namespace Listeners
{
	class ObjectEventListener : Listeners::EventListener
	{
		public:
			/* Events */
			void onHit(Physics::MovingObject &object); // when hitted by another object
			void onBorderHit(Border border); // when touching a border
			void onBorderDisappearance(Border border); // when the object is gone through a border
			void onClicked(Click click); // when clicked, telling left from right click
	};
}

#endif