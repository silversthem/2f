/*
 * A frame is a window displaying a segment of a plan and answering to events.
 * A frame is also a listener, its events can be overwritten.
 * A frame also contains a timer.
 */

#include <SFML/Window.hpp>
/* F2 */
#include "EventMachine.hpp"
#include "Plan.hpp"

namespace F2
{
	class Frame : public Plan, public EventMachine, public sf::RenderWindow
	{
	protected:
		
	public:
		
	};
};
