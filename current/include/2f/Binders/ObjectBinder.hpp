/*
 * An ObjectBinder is an ActionBinder where the action is an object method
 */

#ifndef OBJECTBINDER_HPP
#define OBJECTBINDER_HPP

#include <functional>
/* 2f */
#include "ActionBinder.hpp"

namespace F2
{
	class Object; // Injection

	template<typename ObjectType,typename ArgumentType>
	class ObjectBinder : public ActionBinder<ArgumentType>
	{
	protected:
		ObjectType *_object; // Object on which to apply the method
		std::function<void (const ArgumentType&,ObjectType*)> _action; // Action to perform on the object
		std::function<bool (const ArgumentType&,ObjectType*)> _filter; // If we should be perform the action on the object
		virtual void action(ArgumentType const& arg) // Call the action on the object
		{
			if(_object != 0 && _action) // If there's an action to perform
			{
				if(_filter) // If there's a filter
				{
					if(!_filter(arg,_object)) return;
				}
				_action(arg,_object);
			}
		}
	public:
		ObjectBinder() // Creates an object binder
		{
			_object = 0;
		}
		/* Setters */
		void bind(ObjectType *o,std::function<void (const ArgumentType&,ObjectType*)> const& action) // Binds object & method to the objectBinder
		{
			set_object(o);
			set_action(action);
		}
		void set_object(ObjectType *o) // Sets the object for the objectBinder
		{
			_object = o;
		}
		void set_action(std::function<bool (const ArgumentType&,ObjectType*)> const& action) // Sets the method to call on object
		{
			_action = action;
		}
		virtual void set_filter(std::function<bool (const ArgumentType&,ObjectType*)> const& filter) // Sets filter
		{
			_filter = filter;
		}
	};
};

#endif