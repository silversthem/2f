/*
 * An ObjectContainer is a container for objects
 * Useful for rendering, testing and else
 */

#ifndef OBJECTCONTAINER_HPP
#define OBJECTCONTAINER_HPP

#define LParent ListenerContainer<std::vector<Object*>,std::vector<Object*>::iterator,Object,User> 

#include "ListenerContainer.hpp"

namespace F2
{
	template <typename User>
	class ObjectContainer : public LCONTAINER(Object,User)
	{
	protected:
		void (User::*_onAdd)(Object*); // When adding an object in the container
	public:
		ObjectContainer()
		{
			_onAdd = 0;
		}
		virtual void onAdd(void (User::*onAdd)(Object*)) // When adding
		{
			_onAdd = onAdd;
		}
		virtual void add(Object *o) // Adds an object
		{
			if(_onAdd != 0)
			{
				_onAdd(o);
			}
			if(LParent::_connection)
			{
				o->connect();
			}
		}
	};
};

#endif