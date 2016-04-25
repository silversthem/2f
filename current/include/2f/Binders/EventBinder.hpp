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
#include "ActionBinder.hpp"
#include "../Listeners/Listener.hpp"

namespace F2
{
	class EventBinder : public Listener
	{
	protected:
		std::map<sf::Event::EventType,ActionBinder*> _bounds; // Action binders
		// Time binders
		/* Methods */
		void go_through(sf::Event::EventType const& etype,sf::Event *e); // Goes through action binders & time binders for an event
	public:
		EventBinder();
		/* Adders */
		void bind(sf::Event::EventType const& etype,ActionBinder* action); // Binds action binders
		// Binds time binders
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