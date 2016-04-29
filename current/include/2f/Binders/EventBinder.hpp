/*
 * An EventBinder calls callables on certain events.
 * This allows for multiple subclasses to have event reactions.
 * For example : Handling animation in entity and motion in MovingObject
 */

#ifndef EVENTBINDER_HPP
#define EVENTBINDER_HPP

#include <map>
/* 2f */
#include "../Listeners/Listener.hpp"

namespace F2
{
	template<typename ArgType>
	class Callable; // Injection

	class EventBinder : public Listener
	{
	protected:
		
	public:
		EventBinder();
		/* Adders */
		
		/* Key events */
		void  onKeyPressed(sf::Event *e); // When a key is pressed
		void onKeyReleased(sf::Event *e); // When a key is pressed
		/* Mouse events */
		void  onMouseClicked(sf::Event *e); // When there's a mouse click
		void onMouseReleased(sf::Event *e); // When the mouse button is released
		void    onMouseMoved(sf::Event *e); // When the mouse moves
		/* Other events */
		void onEvent(sf::Event *e); // Non handled event
		void onTicked(int const& tick); // On ticked
	};
};

#endif