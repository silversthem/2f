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
#include "Callable.hpp"

namespace F2
{
	class EventBinder : public Listener
	{
	protected:
		std::map<sf::Event::EventType,std::pair<std::string,Callable<sf::Event*> > > _binders; // Callable called at every event
		std::map<std::string,Callable<int> >  _timers; // Callable called at every tick update
	public:
		EventBinder();
		/* Adders */
		
		/* Deleters */
		
		/* Methods */
	};
};

#endif