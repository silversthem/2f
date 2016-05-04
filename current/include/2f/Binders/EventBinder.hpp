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
		std::map<sf::Event::EventType,std::map<std::string,Callable<sf::Event*>*> > _binders; // Callable called at every event
		std::map<std::string,Callable<int> > _timers; // Callable called at every tick update
		std::vector<Callable<sf::Event*> >  _storage; // Event binders are stored here to control access and allow for multiple bindings to same binder
		/* Storage methods */
		void add(); // Adds callable to storage
		void del(); // Deletes callable from storage & linked events in map binders
		/* Methods */
		virtual void handle(sf::Event *e); // Handles callables
		virtual void onTicked(int const& tick); // Handles ticked callables
	public:
		EventBinder();
		/* Adders */
		void bind(sf::Event::EventType const& t,std::string const& name,Callable<sf::Event*> *b); // Binds event to named binder
		void bind(std::string const& name,Callable<int> *b); // Binds name binder to timer
		void key_bind(std::string const& name,Callable<sf::Event*> *b); // Binds callable to keyPress/keyRelease events
		/* Deleters */
		void event_unbind(std::string const& name); // Unbinds from all event binders
		void timer_unbind(std::string const& name); // Unbinds from time binders
		/* Getters */
		Callable<sf::Event*>* event_binded(std::string const& name); // Returns the event binded
		Callable<int>* timer_binded(std::string const& name); // Returns the timer binded

		friend class Frame; // Friendship is magic
	};
};

#endif