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
		std::map<std::string,Callable<int>*> _timers; // Callable called at every tick update
		std::vector<Callable<sf::Event*> >  _storage; // Event binders are stored here to control access and allow for multiple bindings to same binder
		/* Storage methods */
		Callable<sf::Event*>* add(std::function<void (sf::Event*)> &f); // Adds callable to storage and returns pointer to callable position
		void del(); // Deletes callable from linked events in map binders
		/* Methods */
		virtual void handle(sf::Event *e); // Handles callables
		virtual void onTicked(int const& tick); // Handles ticked callables
	public:
		EventBinder();
		/* Adders */
		void bind(sf::Event::EventType const& t,std::string const& name,std::function<void (sf::Event*)> f); // Binds event to named binder
		void bind(std::string const& name,std::function<void (int)> &f); // Binds name binder to timer
		void key_bind(std::string const& name,std::function<void (sf::Event*)> &f); // Binds callable to keyPress/keyRelease events
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