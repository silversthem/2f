#ifndef LISTENER_HPP
#define LISTENER_HPP

/* Methods called by frames */

namespace Listeners
{
	class Listener
	{
		public:
		/* Events */
		void onInit();
		void onClose();
	};
}

#endif