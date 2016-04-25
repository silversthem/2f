/*
 * An ObjectBinder is an ActionBinder where the action is an object method
 */

#ifndef OBJECTBINDER_HPP
#define OBJECTBINDER_HPP

#include "ActionBinder.hpp"

namespace F2
{
	class Object; // Injection

	template<typename ObjectType = Object>
	class ObjectBinder : public ActionBinder
	{
	protected:
		ObjectType *_object; // Object on which to apply the method
		void (ObjectType::*_action)(sf::Event const&); // Action to perform on the object
		virtual void action(sf::Event const& event) // Call the action on the object
		{
			(_object->*_action)(event);
		}
	public:
		ObjectBinder() // Creates an object binder
		{
			
		}
		/* Setters */
		void bind(ObjectType *o,void (ObjectType::*action)(sf::Event const&)) // Binds object & method to the objectBinder
		{
			set_object(o);
			set_action(action);
		}
		void set_object(ObjectType *o) // Sets the object for the objectBinder
		{
			_object = o;
		}
		void set_action(void (ObjectType::*action)(sf::Event const&)) // Sets the method to call on object
		{
			_action = action;
		}
	};
};

#endif